/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:57:10 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/27 14:59:41 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(RPN const & copy)
{
	*this = copy;
}

RPN & RPN::operator=(RPN const & copy)
{
	_tab = copy._tab;
	return (*this);
}

RPN::~RPN()
{}

bool RPN::isArgvOK(std::string argv)
{
	int cpt_digit = 0;
	int cpt_ope = 0;
	argv.erase(remove(argv.begin(), argv.end(), ' '), argv.end());
	for (unsigned int i = 0; i < argv.length(); i++)
	{
		if ((i == 0 || i == 1) && !isdigit(argv[i]))
			return (false);
		else if (isdigit(argv[i]))
			cpt_digit++;
		else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '/' || argv[i] == '*')
			cpt_ope++;
		else
			return (false);
	}
	if (cpt_digit == cpt_ope + 1)
		return (true);
	return (false);
}

void RPN::execRPN(std::string argv)
{
	double first;
	double second;
	unsigned int i = 0;

	argv.erase(remove(argv.begin(), argv.end(), ' '), argv.end());
	while (i < argv.length())
	{
		if (isdigit(argv[i]))
		{
			_tab.push_back(argv[i] - 48);
		}
		else
		{
			second = _tab.back();
			_tab.pop_back();
			first = _tab.back();
			_tab.pop_back();

			//std::cout << b << " " << a << std::endl;

			if (argv[i] == '+')
				_tab.push_back(first + second);
			else if (argv[i] == '-')
				_tab.push_back(first - second);
			else if (argv[i] == '*')
				_tab.push_back(first * second);
			else if (argv[i] == '/')
				_tab.push_back(first / second);
		}
		i++;
	}
	std::cout << _tab[0] << std::endl;
}