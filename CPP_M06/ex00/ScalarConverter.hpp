/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 14:29:17 by epolkhov          #+#    #+#             */
/*   Updated: 2024-12-03 14:29:17 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <regex>
#include <cctype>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		~ScalarConverter() = delete;
		ScalarConverter(ScalarConverter& ) = delete;
		ScalarConverter& operator=(ScalarConverter& ) = delete;
	public:
		static void convert(std::string arg);
};


#endif