/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 15:27:19 by epolkhov          #+#    #+#             */
/*   Updated: 2024-12-03 15:27:19 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void processChar(long n)
{
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
	{
		std::cout<<"char: impossible"<<std::endl;
	}
	else if(!std::isprint(static_cast<char>(n)))
	{
		std::cout << "char: Non displayable"<< std::endl;
	}
	else{
		std::cout<< "char: '"<< static_cast<char>(n) << "'"<< std::endl;
	}
}
static void processInt(long n)
{
	if ((std::isinf(n) || std::isnan(n)) || \
		(n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max()))
	{
		std::cout << "int: impossible"<< std::endl;
	}
	else
	{
		std::cout<<"int: "<< static_cast<int>(n)<< std::endl;
	}
}

static void processFloat(double n)
{
	if (!std::isinf(n) && !std::isnan(n) && (n < std::numeric_limits<float>::lowest() || \
			n > std::numeric_limits<float>::max()))
	{
		std::cout<< "float: impossible"<< std::endl;
	}
	std::cout<<"float: "<<std::fixed<< std::setprecision(1)<< static_cast<float>(n)<<"f"<<std::endl;
}

static void processDouble(double n)
{
	if (!std::isinf(n) && !std::isnan(n) && (n < std::numeric_limits<double>::lowest() || \
			n > std::numeric_limits<double>::max()))
	{
		std::cout<< "double: impossible"<< std::endl;
	}
	std::cout<<"double: "<<std::fixed<< std::setprecision(1)<< static_cast<double>(n)<<std::endl;
}

static void convertToChar(char arg)
{
	processChar(arg);
	processInt(arg);
	processFloat(arg);
	processDouble(arg);
}

static void convertToFloat(std::string arg)
{
	float n = std::stof(arg);
	processChar(n);
	processInt(n);
	processFloat(n);
	processDouble(n);
}

static void convertToDouble(std::string arg)
{
	double n = std::stod(arg);
	processChar(n);
	processInt(n);
	processFloat(n);
	processDouble(n);
}

static void convertToInt(std::string arg)
{
	int n = std::stoi(arg);
	processChar(n);
	processInt(n);
	processFloat(n);
	processDouble(n);
}

void ScalarConverter::convert(std::string arg)
{
	try
	{
		if (arg.length() == 1 && isalpha(arg[0]))
			convertToChar(arg[0]);
		else if (arg == "inff" || arg == "-inff" || arg == "nanf" || \
				(arg.find('.') != std::string::npos && arg.find('f') != std::string::npos))
			convertToFloat(arg);
		else if(arg == "inf" || arg == "-inf" || arg == "nan" || arg.find('.') != std::string::npos)
			convertToDouble(arg);
		else
			convertToInt(arg);
	}
	catch(std::exception& e)
	{
		std::cerr << "Error: some exception " << e.what() << std::endl;
	}
}