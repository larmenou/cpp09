/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:37:08 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/22 15:01:54 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::isFileOk(std::ifstream & ifs)
{
	if (!ifs.is_open())
	{
		std::cerr << "Error while opening infile." << std::endl;
		return (false);
	}
	
}