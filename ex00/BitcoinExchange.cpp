/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:37:08 by larmenou          #+#    #+#             */
/*   Updated: 2024/03/04 07:30:49 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	*this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & copy)
{
	_data = copy._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

bool BitcoinExchange::isFileOk(std::ifstream & ifs, char* filename)
{
	ifs.open(filename);
	if (!ifs.is_open())
	{
		return (false);
	}
	return (true);
}

bool BitcoinExchange::extractData()
{
	std::ifstream ifs;
	std::string line;
	std::string date_str;
	std::string tmp;
	float rate;
	std::size_t pos = 0;
	std::stringstream ss;
	
	ifs.open("data.csv");
	if (ifs.is_open() == false)
	{
		std::cout << "Error while opening data.csv" << std::endl;
		return (false);
	}
	
	while (getline(ifs, line))
	{
		pos = line.find(",", pos);
		date_str = line.substr(0, pos);
		tmp = line.substr(pos + 1);
		
		ss.clear();
		ss.str(tmp);
		ss >> rate;

		if (!ss.fail())
			_data.insert(std::map<std::string, float>::value_type(date_str, rate));
	}

	return (true);
}

bool BitcoinExchange::checkDateFormat(std::string date)
{
	std::string year_str;
	std::string month_str;
	std::string day_str;
	int year;
	int month;
	int day;
	std::stringstream ss;
	int year_data;
	int month_data;
	int day_data;
	
	if (date.length() == 10 && date[4] && date[7] && date[4] == '-' && date[7] == '-')
	{
		for (unsigned int i = 0; i < date.length(); i++)
		{
			if (i != 4 && i != 7 && isdigit(date[i]))
				continue ;
			else if (i != 4 && i != 7 && !isdigit(date[i]))
			{
				std::cout << "Error: bad date => " << date << std::endl;
				return (false);
			}
		}
	}
	else
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return (false);
	}

	year_str = date.substr(0, 4);
	month_str = date.substr(5, 2);
	day_str = date.substr(8, 2);

	ss.str(year_str);
	ss >> year;

	ss.clear();
	ss.str(month_str);
	ss >> month;
	
	ss.clear();
	ss.str(day_str);
	ss >> day;

	ss.clear();
	ss.str(_data.begin()->first.substr(0, 4));
	ss >> year_data;

	ss.clear();
	ss.str(_data.begin()->first.substr(5, 2));
	ss >> month_data;

	ss.clear();
	ss.str(_data.begin()->first.substr(8, 2));
	ss >> day_data;

	if ((year == year_data && month == month_data && day < day_data)
		|| (year == year_data && month < month_data)
		|| (year < year_data)
		|| (month == 0 || day == 0)
		|| (month > 12)
		|| (month == 2 && year % 4 != 0 && day > 28)
		|| (month % 2 == 1 && day > 31)
		|| (month % 2 == 0 && month != 8 && day > 30))
	{
		std::cout << "Error: bad date => " << date << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::checkValue(std::string value)
{
	float val;
	std::stringstream ss;

	ss.str(value);
	ss >> val;

	if (val < 0)
	{
		std::cout << "Error: not a positive number => " << val << std::endl;
		return (false);
	}
	else if (val > 1000)
	{
		std::cout << "Error: too large number => " << val << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::findValueInMap(std::string line)
{
	std::map<std::string, float>::iterator itlow;
	std::string date;
	std::string nb_bc;
	std::size_t pos = 0;
	std::stringstream ss;
	float amount;

	pos = line.find('|');
	if (pos == line.length() || pos == line.length() - 1 || pos == 0)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}

	date = line.substr(0, pos);
	if (date[date.length() - 1] == ' ')
	{
		date.resize(date.length() - 1);
		if (!checkDateFormat(date))
			return ;
	}
	else
	{
		std::cout << "Error: bad date => " << line << std::endl;
		return ;
	}
	
	nb_bc = line.substr(pos + 1);
	if (nb_bc[0] == ' ')
	{
		nb_bc = nb_bc.substr(1);
		for(unsigned int i = 0; i < nb_bc.length(); i++)
		{
			if (nb_bc[0] == '-' || nb_bc[i] == '.')
				continue ;
			else if (!isdigit(nb_bc[i]))
			{
				std::cout << "Error: bad number format => " << nb_bc << std::endl;
				return ;
			}
		}
		if (!checkValue(nb_bc))
		return ;
	}
	
	ss.str(nb_bc);
	ss >> amount;

	itlow = _data.find(date);
	if (itlow != _data.end())
	{
		std::cout << itlow->first << " => " << nb_bc << " = " << amount * itlow->second << std::endl;
		return ;
	}

	itlow = _data.lower_bound(date);
	itlow--;

	std::cout << date << " => " << nb_bc << " = " << amount * itlow->second << std::endl;
}