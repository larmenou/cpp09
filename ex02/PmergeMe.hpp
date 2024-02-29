/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:26:28 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/29 11:17:15 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

class PmergeMe
{
	private:
		struct s_elem
		{
			int elem;
			int index;
		} typedef t_elem;
		
		std::vector<t_elem> _vector;
		std::vector<t_elem> _s_vector;
		std::list<t_elem> _list;
		std::list<t_elem> _s_list;

		void updateIndexVector();
		void mergeSortVector(t_elem e);

		void updateIndexList();
		void mergeSortList(t_elem e);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const & copy);
		PmergeMe & operator=(PmergeMe const & copy);
		~PmergeMe();
		
		void addElemVector(int elem);
		void sortPairVector();
		void printVector();
		void splitVector();
		void insertionSortVector();
		void addFirstIndexVector();
		void jacobsthalNumbersSortVector();

		void addElemList(int elem);
		void sortPairList();
		void splitList();
		void insertionSortList();
		void addFirstIndexList();
		void jacobsthalNumbersSortList();

		bool isSortedVector();
		bool isSortedList();
};

bool isNumber(std::string str);