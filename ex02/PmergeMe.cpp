/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:26:31 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/28 16:49:20 by larmenou         ###   ########.fr       */
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
	return (*this);
}

PmergeMe::~PmergeMe()
{}

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
	std::vector<t_elem> newVector;
	
	for (v_it = _vector.begin(); v_it != _vector.end(); v_it++)
	{
		if (std::distance(_vector.begin(), v_it) % 2 == 1)
		{
			_s_vector.push_back(*v_it);
		}
		else
		{
			newVector.push_back(*v_it);
		}
	}

	_vector = newVector;		
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

void PmergeMe::updateIndex()
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

void PmergeMe::addFirstIndex()
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
	updateIndex();
}

void PmergeMe::mergeSortVector(t_elem e)
{
	if (_s_vector.empty()) {
		_s_vector.push_back(e);
		return;
	}

	int low = 0;
	int high = _s_vector.size() - 1;
	int mid;

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

void PmergeMe::jacobsthalNumbersSort()
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