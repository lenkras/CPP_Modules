/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    BitcoinExchange.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 09:09:28 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-25 09:09:28 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <regex>
#include <ctime>
#include <iomanip>
#include <cmath>

struct Data{
	//std::multimap<std::string, float> input;
	std::vector<std::pair<std::string, float>> input;
    std::map<std::string, float> rate;
};

class BitcoinExchange
{
	private:
		Data map;
		//std::map<std::string, float> result;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void parseFile(const std::string& file, const char delim);
		bool checkExtension(const std::string& filename, const std::string& end);
		bool checkDate(const std::string& date);
		void calcExchangeRate();

};