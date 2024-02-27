/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:36:55 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/27 10:30:42 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::ifstream ifs;
	std::string line;
	BitcoinExchange be;

	if (ac != 2 || !be.isFileOk(ifs, av[1]))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	if (!be.extractData())
		return (1);
	getline(ifs, line);
	while (getline(ifs, line))
	{
		be.findValueInMap(line);
	}
	return (0);
}