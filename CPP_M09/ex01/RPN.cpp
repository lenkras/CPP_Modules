/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 09:06:20 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-25 09:06:20 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN::parseString(const std::string& str)
{
	int finalResult;
	if (str.empty())
		throw std::invalid_argument("Error: empty string.");
	if (str.size() < 3)
	{
		throw std::invalid_argument("Error: not enough operands for operation");
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			continue ;
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+' ||
				 str[i] == '*' || str[i] == '/'))
		{
			throw std::invalid_argument("Error: invalid input.");
		}
		if (i + 1 < str.size()) 
        {
            if (str[i + 1] != ' ' && str[i + 1] != '\0' )
            {
                throw std::invalid_argument("Error: invalid input (no space or end of line after operator).");
            }
        }
		if (isdigit(str[i]))
		{
			stack.push(str[i] - '0');
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int result = applyOperator(a, b, str[i]);
			stack.push(result);
			finalResult = result;
			if (finalResult > INT_MAX || finalResult < INT_MIN)
			{
				throw std::out_of_range("overflow");
			}
		}
	}
	if (stack.size() != 1) {
        std::cerr << "Error: invalid RPN expression" << std::endl;
        return;
    }
	std::cout << finalResult << std::endl;

}

int RPN::applyOperator(int a, int b, char oper)
{
    switch (oper) {
        case '+': 
			if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
				throw std::overflow_error(" overflow");
			return a + b;
        case '-': 
			if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
				throw std::overflow_error(" overflow");
			return a - b;
        case '*': 
			if (a > INT_MAX / b || a < INT_MIN / b)
				throw std::overflow_error("overflow");
			return a * b;
        case '/':
            if (b == 0) {
                std::cerr << "Error: division by zero" << std::endl;
                throw std::invalid_argument("division by zero");
            }
            return a / b;
        default:
            throw std::invalid_argument("invalid operator");
    }
}