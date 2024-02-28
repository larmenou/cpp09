/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:26:28 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/28 15:45:39 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

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

		void updateIndex();
		void mergeSortVector(t_elem e);

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
		void addFirstIndex();
		void jacobsthalNumbersSort();
};