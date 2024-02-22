/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:37:11 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/22 14:41:16 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
	private:

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & copy);
		~BitcoinExchange();
		BitcoinExchange & operator=(BitcoinExchange const & copy);

		bool isFileOk(std::ifstream & ifs);
};