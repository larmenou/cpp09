/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:36:55 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/29 11:35:27 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe p;
	std::stringstream ss;
	int elem;

	if (ac == 1)
	{
		std::cout << "Error: not enough arguments" << std::endl;
		return (1);
	}

	std::clock_t c_start_one = std::clock();
	for (int i = 1; i < ac; i++)
	{
		ss.clear();
		if (isNumber(av[i]))
		{
			ss.str(av[i]);
			ss >> elem;
			p.addElemVector(elem);
		}
		else
		{
			std::cout << "Error: not an integer" << std::endl;
			return (1);
		}
	}
	std::clock_t c_end_one = std::clock();

	std::cout << "Before :  ";
	p.printVector();
	
	std::clock_t c_start = std::clock();
	if (ac > 2)
	{
		p.sortPairVector();
		p.splitVector();
		p.insertionSortVector();
		p.addFirstIndexVector();
		p.jacobsthalNumbersSortVector();
	}

	std::clock_t c_end = std::clock();

	std::cout << "After :   ";
	p.printVector();
	
	double time_elapsed_ms = 1000.0 * ((c_end - c_start) + (c_end_one - c_start_one)) / CLOCKS_PER_SEC;
	std::cout << "Time to proccess a range of " << ac - 1 << " elements with std::vector : " << time_elapsed_ms << " ms" << std::endl;
	
	/* 
		List
	*/
	
	c_start = std::clock();
	for (int i = 1; i < ac; i++)
	{
		ss.clear();
		if (isNumber(av[i]))
		{
			ss.str(av[i]);
			ss >> elem;
			p.addElemList(elem);
		}
		else
		{
			std::cout << "Error: not an integer" << std::endl;
			return (1);
		}
	}
	
	if (ac > 2)
	{
		p.sortPairList();
		p.splitList();
		p.insertionSortList();
		p.addFirstIndexList();
		p.jacobsthalNumbersSortList();
	}
	

	c_end = std::clock();
	time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
	std::cout << "Time to proccess a range of " << ac - 1 << " elements with std::list   : " << time_elapsed_ms << " ms" << std::endl;
	
	if (p.isSortedVector())
		std::cout << "Vector is sorted." << std::endl;
	else
		std::cout << "Vector is NOT sorted." << std::endl;

	if (p.isSortedList())
		std::cout << "List is sorted." << std::endl;
	else
		std::cout << "List is NOT sorted." << std::endl;

	return (0);
}