/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:57:06 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/27 14:31:24 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class RPN
{
	private:
		std::vector<double> _tab;

	public:
		RPN();
		RPN(RPN const & copy);
		RPN & operator=(RPN const & copy);
		~RPN();

		bool isArgvOK(std::string argv);
		void execRPN(std::string argv);
};