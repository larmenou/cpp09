/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:37:11 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/27 10:40:36 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <ctype.h>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & copy);
		~BitcoinExchange();
		BitcoinExchange & operator=(BitcoinExchange const & copy);

		bool isFileOk(std::ifstream & ifs, char* filename);
		bool extractData();
		bool checkDateFormat(std::string date);
		bool checkValue(std::string value);
		void findValueInMap(std::string line);
};
