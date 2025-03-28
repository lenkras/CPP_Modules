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
	if (year < 2009 || year > 2025 || month < 1 || month > 12 || day < 1) {
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
        throw std::ios_base::failure("cannot open a file.");
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
        throw std::ios_base::failure("cannot open a file.");
    }
    
    std::string line;
    if (!std::getline(inputFile, line) || line.empty())
    {
        throw std::runtime_error("empty file");
    }
    line.erase(0, line.find_first_not_of(" \t"));
    line.erase(line.find_last_not_of(" \t") + 1);
    
    if (line != "date | value")
    {
        throw std::invalid_argument("invalid first line");
    }

    if (delim == '|')
    {
        while (std::getline(inputFile, line))
        {
            std::stringstream ss(line);
            std::string date;
            std::string value;
            float num = 0;

            if (std::getline(ss, date, '|'))
            {
                date.erase(0, date.find_first_not_of(' '));
                date.erase(date.find_last_not_of(' ') + 1);
				std::time_t t = std::time(nullptr);
				std::tm* now = std::localtime(&t);
				char current_date[11];
				std::strftime(current_date, sizeof(current_date), "%Y-%m-%d", now);
				if (!checkDate(date) || date > current_date)
                {
                    std::cerr << "Error: bad input => " << date << std::endl;
                    continue;
                }
                if (ss >> value)
                {
                    value.erase(0, value.find_first_not_of(' '));
                    value.erase(value.find_last_not_of(' ') + 1);

                    bool valid = true;
                    size_t dot_count = 0;
                    for (size_t i = 0; i < value.size(); ++i)
                    {
                        char c = value[i];
                        if (i == 0 && c == '-') {
                            continue;
                        }
                        else if (c == '.' && ++dot_count <= 1) {
                            continue;
                        }
                        else if (!isdigit(c)) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        std::cerr << "Error: invalid value format => " << value << std::endl;
                        continue;
                    }

                    try {
                        num = std::stof(value);
                        
                        if (num <= 0) {
                            std::cerr << "Error: not a positive number." << std::endl;
                            continue;
                        }
                        if (num > 1000) {
                            std::cerr << "Error: too large a number." << std::endl;
                            continue;
                        }
                    }
                    catch (...) {
                        std::cerr << "Error: invalid number => " << value << std::endl;
                        continue;
                    }
                    processExchangeRate(date, num);
                }
                else
                {
                    std::cerr << "Error: missing value for date " << date << std::endl;
                }
            }
        }
    }
    else
    {
        inputFile.close();
        throw std::invalid_argument("Invalid file");
    }
    inputFile.close();
}

void BitcoinExchange::processExchangeRate(const std::string& date, float value)
{
    float rateValue;
    auto rateKey = rate.find(date);

    if (rateKey != rate.end())
    {
        rateValue = rateKey->second;
        if (rateValue <= 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            return;
        }
    }
    else
    {
        rateKey = rate.lower_bound(date);
        if (rateKey == rate.begin())
        {
            std::cerr << "Error: No lower date found for " << date << std::endl;
            return;
        }
		--rateKey;
        rateValue = rateKey->second;
    }

    float resultValue = rateValue * value;
    if (resultValue > 2147483647.0)
    {
        std::cerr << "Error: value too large" << std::endl;
        return;
    }

    formatAndPrintResult(date, value, resultValue);
}

void BitcoinExchange::formatAndPrintResult(const std::string& date, float value, float resultValue)
{
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
