/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:36:55 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/28 15:16:16 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe p;
	std::stringstream ss;
	int elem;

	if (ac == 1)
		return (1);

	for (int i = 1; i < ac; i++)
	{
		ss.clear();
		ss.str(av[i]);
		ss >> elem;
		p.addElemVector(elem);
	}
	
	std::cout << "Before :  ";
	p.printVector();
	p.sortPairVector();
	p.splitVector();
	p.insertionSortVector();
	p.addFirstIndex();
	p.jacobsthalNumbersSort();

	std::cout << "After :   ";
	p.printVector();
	
	return (0);
}