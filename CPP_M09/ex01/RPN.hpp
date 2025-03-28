/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 09:06:10 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-25 09:06:10 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <climits>

class RPN
{
	private:
		std::stack<int> stack;
	public:
		RPN(){};
		~RPN(){};
		
		void parseString(const std::string& str);
		int applyOperator(int a, int b, char oper);


};