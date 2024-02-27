/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:36:55 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/27 14:40:44 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN rpn;
	if (ac != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::string str(av[1]);
	
	if (!rpn.isArgvOK(str))
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	rpn.execRPN(str);
	return (0);
}