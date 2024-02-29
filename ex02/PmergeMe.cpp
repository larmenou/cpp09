/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:26:31 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/29 11:20:32 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	*this = copy;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & copy)
{
	_vector = copy._vector;
	_s_vector = copy._s_vector;
	_list = copy._list;
	_s_list = copy._s_list;
	return (*this);
}

PmergeMe::~PmergeMe()
{}

bool isNumber(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}

void PmergeMe::addElemVector(int elem)
{
	t_elem e;

	e.elem = elem;
	e.index = 0;
	_vector.push_back(e);
}

void PmergeMe::sortPairVector()
{
	int tmp = 0;
	int idx = 1;
	
	for (unsigned int i = 0; i < _vector.size(); i += 2)
	{
		if (_vector[i + 1].elem && _vector[i + 1].elem < _vector[i].elem)
		{
			tmp = _vector[i].elem;
			_vector[i].elem = _vector[i + 1].elem;
			_vector[i + 1].elem = tmp;
		}
		_vector[i + 1].index = idx;
		_vector[i].index = idx;
		idx++;
	}
}

void PmergeMe::printVector()
{
	for (unsigned int i = 0; i < _vector.size(); i++)
		std::cout << _vector[i].elem << " ";
	std::cout << std::endl;
}

void PmergeMe::splitVector()
{
	std::vector<t_elem>::iterator v_it;
	std::vector<t_elem> new_vector;
	
	for (v_it = _vector.begin(); v_it != _vector.end(); v_it++)
	{
		if (std::distance(_vector.begin(), v_it) % 2 == 1)
		{
			_s_vector.push_back(*v_it);
		}
		else
		{
			new_vector.push_back(*v_it);
		}
	}

	_vector = new_vector;		
}

void PmergeMe::insertionSortVector()
{
	for (size_t i = 1; i < _s_vector.size(); i++)
	{
		t_elem key = _s_vector[i];
		int j = i - 1;

		while (j >= 0 && _s_vector[j].elem > key.elem)
		{
			_s_vector[j + 1] = _s_vector[j];
			j--;
		}
		_s_vector[j + 1] = key;
	}
}

void PmergeMe::updateIndexVector()
{
	for(unsigned int i = 2; i < _s_vector.size(); i++)
	{
		for (unsigned int j = 0; j < _vector.size(); j++)
		{
			if (_s_vector[i].index == _vector[j].index)
			{
				_s_vector[i].index = i;
				_vector[j].index = i;
				break ;
			}
		}
	}
}

void PmergeMe::addFirstIndexVector()
{
	std::vector<t_elem>::iterator it = _s_vector.begin();
	std::vector<t_elem> newVector;

	for (unsigned int i = 0; i < _vector.size(); i++)
	{
		if (_vector[i].index == _s_vector[0].index)
			_s_vector.insert(it, _vector[i]);
		else
			newVector.push_back(_vector[i]);
	}
	_vector = newVector;
	updateIndexVector();
}

void PmergeMe::mergeSortVector(t_elem e)
{
	int low = 0;
	int high = _s_vector.size() - 1;
	int mid;
	
	if (_s_vector.empty()) {
		_s_vector.push_back(e);
		return;
	}

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (_s_vector[mid].elem == e.elem)
		{
			_s_vector.insert(_s_vector.begin() + mid, e);
			return;
		}
		else if (_s_vector[mid].elem < e.elem)
		{
			low = mid + 1;
		}
		else 
		{
			high = mid - 1;
		}
	}
	_s_vector.insert(_s_vector.begin() + low, e);
}

void PmergeMe::jacobsthalNumbersSortVector()
{
	int jn_1;
	int jn_2;
	int jn;
	int cpt_jn;
	size_t cpt = 0;
	size_t i;

	for (size_t i = 1; i < _vector.size(); i++)
	{
		t_elem key = _vector[i];
		int j = i - 1;

		while (j >= 0 && _vector[j].index > key.index)
		{
			_vector[j + 1] = _vector[j];
			j--;
		}
		_vector[j + 1] = key;
	}
	
	while (cpt < _vector.size())
	{
		if (cpt == 2)
		{
			jn_2 = 2;
			jn_1 = 2;
			jn = 2;
			i = jn + 1;
		}
		else if (cpt == 0)
		{
			jn_2 = 2;
			jn_1 = 2;
			jn = 2;
			i = jn - 1;
		}
		else
			i = jn - 1 + jn_1 + jn_2;
		cpt_jn = 0;
		if (i >= _vector.size())
		{
			cpt_jn = i - _vector.size() + 1;
			i = _vector.size() - 1;
		}
		while (cpt_jn < jn)
		{
			mergeSortVector(_vector[i]);
			i--;
			cpt_jn++;
			cpt++;
		}
		if (i == _vector.size() - cpt_jn - 1)
			break ;
		jn_2 = jn_1;
		jn_1 = jn;
		jn = jn_1 + 2 * jn_2;
	}
	_vector = _s_vector;
}

void PmergeMe::addElemList(int elem)
{
	t_elem e;

	e.elem = elem;
	e.index = 0;
	_list.push_back(e);
}

void PmergeMe::sortPairList()
{
	int tmp = 0;
	int idx = 1;
	size_t cpt = 0;

	for (std::list<t_elem>::iterator it = _list.begin(); it != _list.end(); )
	{
		std::list<t_elem>::iterator next_it = it;
		std::advance(next_it, 1);
		if (next_it != _list.end())
		{
			if (next_it->elem && next_it->elem < it->elem)
			{
				tmp = it->elem;
				it->elem = next_it->elem;
				next_it->elem = tmp;
			}
			next_it->index = idx;
			it->index = idx;
			idx++;
		}
		std::advance(it, 2);
		cpt += 2;
		if (cpt > _list.size())
			break ;
	}
}

void PmergeMe::splitList()
{
	std::list<t_elem>::iterator it;
	std::list<t_elem> new_list;
	
	for (it = _list.begin(); it != _list.end(); it++)
	{
		if (std::distance(_list.begin(), it) % 2 == 1)
		{
			_s_list.push_back(*it);
		}
		else
		{
			new_list.push_back(*it);
		}
	}

	_list = new_list;
}

void PmergeMe::insertionSortList()
{
	for (std::list<t_elem>::iterator it = _s_list.begin(); it != _s_list.end(); it++)
	{
		std::list<t_elem>::iterator prev_it = it;
		t_elem key = *it;
		
		while (prev_it != _s_list.begin() && (*(--prev_it)).elem > key.elem)
		{
			std::swap(*prev_it, *it);
			it--;
		}
	}
}

void PmergeMe::updateIndexList()
{
	int i = 2;
	
	std::list<t_elem>::iterator s_it = _s_list.begin();
	std::advance(s_it, 2);
	for(; s_it != _s_list.end(); s_it++)
	{
		for (std::list<t_elem>::iterator it = _list.begin(); it != _list.end(); it++)
		{
			if (s_it->index == it->index)
			{
				s_it->index = i;
				it->index = i;
				break ;
			}
		}
		i++;
	}
}

void PmergeMe::addFirstIndexList()
{
	std::list<t_elem>::iterator it_b = _s_list.begin();
	std::list<t_elem> new_list;

	for (std::list<t_elem>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		if (it->index == it_b->index)
			_s_list.insert(it_b, *it);
		else
			new_list.push_back(*it);
	}
	_list = new_list;
	updateIndexList();
}

void PmergeMe::mergeSortList(t_elem e)
{
	std::list<t_elem>::iterator low = _s_list.begin();
	std::list<t_elem>::iterator high = _s_list.end();
	std::list<t_elem>::iterator mid;
	
	if (_s_list.empty()) {
		_s_list.push_back(e);
		return;
	}

	while (low != high)
	{
		mid = low;
		std::advance(mid, std::distance(low, high) / 2);
		if (mid->elem == e.elem)
		{
			_s_list.insert(mid, e);
			return;
		}
		else if (mid->elem < e.elem)
		{
			low++;
		}
		else 
		{
			high = mid;
		}
	}
	_s_list.insert(low, e);
}

void PmergeMe::jacobsthalNumbersSortList()
{
	int jn_1;
	int jn_2;
	int jn;
	int cpt_jn;
	size_t cpt = 0;
	size_t i;
	std::list<t_elem>::iterator beg = _list.begin();
	std::list<t_elem>::iterator end = _list.end();

	for (std::list<t_elem>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::list<t_elem>::iterator prev_it = it;
		t_elem key = *it;
		
		while (prev_it != _list.begin() && (*(--prev_it)).elem > key.elem)
		{
			std::swap(*prev_it, *it);
			it--;
		}
	}
	
	while (beg != end)
	{
		if (cpt == 2)
		{
			jn_2 = 2;
			jn_1 = 2;
			jn = 2;
			std::advance(beg, jn + 1);
		}
		else if (cpt == 0)
		{
			jn_2 = 2;
			jn_1 = 2;
			jn = 2;
			std::advance(beg, jn - 1);
		}
		else
		{
			i = jn - 1 + jn_1 + jn_2;
			std::advance(beg, i);
		}

		cpt_jn = 0;
		while (cpt_jn < jn)
		{
			mergeSortList(*beg);
			--beg;
			++cpt_jn;
			++cpt;
		}

		if (std::distance(beg, end) == cpt_jn)
			break;

		jn_2 = jn_1;
		jn_1 = jn;
		jn = jn_1 + 2 * jn_2;
	}
	_list = _s_list;
}

bool PmergeMe::isSortedList()
{
	if (_list.empty() || _list.size() == 1)
	{
		return true;
	}

	std::list<t_elem>::iterator it = _list.begin();
	std::list<t_elem>::iterator next_it = it;

	next_it++;

	while (next_it != _list.end())
	{
		if ((*next_it).elem < (*it).elem) 
		{
			return false;
		}
		++it;
		++next_it;
	}

	return true;
}

bool PmergeMe::isSortedVector()
{
	if (_vector.empty() || _vector.size() == 1)
	{
		return true;
	}

	std::vector<t_elem>::iterator it = _vector.begin();
	std::vector<t_elem>::iterator next_it = it;

	next_it++;

	while (next_it != _vector.end())
	{
		if ((*next_it).elem < (*it).elem) 
		{
			return false;
		}
		++it;
		++next_it;
	}

	return true;
}