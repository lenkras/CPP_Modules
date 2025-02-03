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

static bool isValidIntString(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) 
	{
        if (!(std::isdigit(str[i]) || (i == 0 && (str[i] == '-' || str[i] == '+'))))
		{
            return false;
		}
    }
    return true;
}

static bool isSpecialInput(const std::string& arg) 
{
    if (arg == "+inf" || arg == "-inf" || arg == "nan" || 
        arg == "+inff" || arg == "-inff" || arg == "nanf")
	{
        return true;
	}
    return false;
}


void ScalarConverter::convert(std::string arg)
{
	try
	{
		if (isSpecialInput(arg))
		{
            if (arg == "+inf" || arg == "-inf" || arg == "nan")
                convertToDouble(arg);
			else if (arg == "+inff" || arg == "-inff" || arg == "nanf")
                convertToFloat(arg);
			return ;
        }
		if (arg.find('.')!= std::string::npos)
		{
			 if (arg.back() == 'f') 
            {
                if (std::count(arg.begin(), arg.end(), '.') > 1)
                {
                    throw std::invalid_argument("Invalid format: multiple dots found.");
                }
                if (!std::isdigit(arg[arg.length() - 2])) 
                {
                    throw std::invalid_argument("Invalid format: character before 'f' is not a digit.");
                }
                convertToFloat(arg);
            }
            else if (std::isdigit(arg.back()))
            {
                if (std::count(arg.begin(), arg.end(), '.') > 1 || !isValidIntString(arg))
                {
                    throw std::invalid_argument("Invalid format");
                }
                convertToDouble(arg);
            }
			else{
				throw std::invalid_argument("Invalid format of input");
			}
		}
		else
		{
			if (arg.length() == 1 && isalpha(arg[0]))
				convertToChar(arg[0]);
			else if (isValidIntString(arg))
				convertToInt(arg);
			else
			{
				throw std::invalid_argument("Invalid format of input");
			}
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "Error: some exception: " << e.what() << std::endl;
	}
	catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid argument: " << e.what() << std::endl;
    }
}