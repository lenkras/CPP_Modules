/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    BitcoinExchange.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 09:09:18 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-25 09:09:18 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::checkExtension(const std::string& filename, const std::string& end)
{
	size_t dotIndex = filename.rfind('.');
	if (dotIndex != std::string::npos && dotIndex != 0)
	{
		std::string ext = filename.substr(dotIndex + 1);
		if (end == ext)
			return true;
	}
	return false;
}

bool BitcoinExchange::checkDate(const std::string& date)
{
	std::regex dateFormat(R"(^\d{4}-\d{2}-\d{2}$)");
	if(!std::regex_match(date, dateFormat))
	{
		return false;
	}
	int year, month, day;
	char dash1, dash2;
	std::istringstream ss(date);
	ss >> year >> dash1 >> month >> dash2 >>day;
	if (ss.fail() || dash1 != '-' || dash2 != '-')
        return false;
	if (year < 2000 || year > 2025 || month < 1 || month > 12 || day < 1) {
        return false;
    }
	const int daysInEveryMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day > 29)
				return false;
		}
		else{
			if (day > 28)
				return false;
		}
	}
	else{
		if (day > daysInEveryMonth[month - 1])
			return false;
	}
	return true;
}

float roundToTwoDecimals(float value) {
    return std::round(value * 100.0) / 100.0;
}

void BitcoinExchange::parseFile(const std::string& file, const char delim)
{
    std::ifstream inputFile(file);
    if (!inputFile)
    {
        throw std::ios_base::failure("Error opening file.");
    }

    std::string line;
    if (checkExtension(file, "csv") && delim == ',')
    {
		while (std::getline(inputFile, line))
		{
			if (line.empty())
				continue ;
			std::stringstream ss(line);
			std::string date;
			float value;
			if (std::getline(ss, date, ',') && ss >> value)
			{
				if (date == "date")
					continue ;
				date.erase(0, date.find_first_not_of(' '));
		        date.erase(date.find_last_not_of(' ') + 1);
				rate[date] += roundToTwoDecimals(value);
			}
		}		
    }
    else
    {
        inputFile.close();
        throw std::invalid_argument("Invalid file extension or delimiter");
    }

    inputFile.close();
}

void BitcoinExchange::calcExchangeRate(const std::string& file, const char delim)
{
	std::ifstream inputFile(file);
    if (!inputFile)
    {
        throw std::ios_base::failure("Error opening file.");
    }
    std::string line;
	bool firstLine = true;
	if (checkExtension(file, "txt") && delim == '|')
	{
		while (std::getline(inputFile, line))
        {
            std::stringstream ss(line);
            std::string date;
            float value = 0;
            if (firstLine)
            {
                firstLine = false;
                continue;
            }
        	if (std::getline(ss, date, '|'))
           	{
                date.erase(0, date.find_first_not_of(' '));
                date.erase(date.find_last_not_of(' ') + 1);
				if (!checkDate(date))
				{
					std::cerr<< "Error: bad input => "<< date << std::endl;
					continue ;
				}
                if (ss >> value)
              	{
					if (value < 0)
					{
						std::cerr << "Error: not a positive number." << std::endl;
						continue;
					}
					if (value > 1000)
					{
						std::cerr << "Error: too large number." << std::endl;
						continue;
					}
				}
         	}
			float rateValue;
			auto rateKey = rate.find(date);
			if (rateKey != rate.end())
			{
				rateValue = rateKey->second;
				if (rateValue <= 0)
				{
					std::cerr << "Error: not a positive number."  << std::endl;
					continue ;
				}
			}
			else{
			rateKey = rate.lower_bound(date);
			rateValue = rateKey->second;
            if (rateKey == rate.begin())
            {
                std::cerr << "Error: No lower date found for " << date << std::endl;
                continue ;
            }
            --rateKey;
			}
			float resultValue = rateValue * value;
			if (resultValue > 2147483647.0)
			{
				std::cerr << "Error: value too large" << std::endl;
				continue ;
			}	
			std::ostringstream oss;
			oss << resultValue;
			std::string resultStr = oss.str();
			if (resultStr.find('.') != std::string::npos)
			{
				resultStr.erase(resultStr.find_last_not_of('0') + 1, std::string::npos);
				if (resultStr.back() == '.')
					resultStr.pop_back();
			}
			std::cout << date << " => " << value << " = " << resultStr << std::endl;

			}
	}
	else
	{
		inputFile.close();
        throw std::invalid_argument("Invalid file extension or delimiter");
	}
	inputFile.close();
}

