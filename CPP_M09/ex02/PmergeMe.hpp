/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-04 10:39:58 by epolkhov          #+#    #+#             */
/*   Updated: 2025-03-04 10:39:58 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <limits>
#include <deque>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <map>
#include <unordered_map>

class PmergeMe
{
	private:
		std::vector<size_t> array;
		std::deque<size_t> arrD;
		std::chrono::microseconds timeAddVector;
    	std::chrono::microseconds timeAddDeque;
    	std::chrono::microseconds timeSortVector;
    	std::chrono::microseconds timeSortDeque;

	public:
		PmergeMe(){};
		~PmergeMe(){};

		std::vector<size_t>& getArray();
		std::deque<size_t>& getDeque();
		bool check_input(const std::string &str);
		void addToVector(const std::string& str);
		void addToDeque(const std::string& str);
		std::vector<size_t> fordJohnsonVector(std::vector<size_t> &array);
		std::deque<size_t> fordJohnsonDeque(std::deque<size_t> &array);
		void sortAndprint(std::vector<size_t> &array, std::deque<size_t>& arrD);

};