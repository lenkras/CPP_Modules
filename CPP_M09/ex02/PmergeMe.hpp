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

class PmergeMe
{
	private:
		std::vector<int> array;
		std::deque<int> arrD;
		std::chrono::microseconds timeAddVector;
    	std::chrono::microseconds timeAddDeque;
    	std::chrono::microseconds timeSortVector;
    	std::chrono::microseconds timeSortDeque;

	public:
		PmergeMe(){};
		~PmergeMe(){};

		std::vector<int>& getArray();
		std::deque<int>& getDeque();
		bool check_input(const std::string &str);
		void addToVector(const std::string& str);
		void addToDeque(const std::string& str);
		std::vector<int> fordJohnsonVector(std::vector<int> &array);
		std::deque<int> fordJohnsonDeque(std::deque<int> &array);
		void sortAndprint(std::vector<int> &array, std::deque<int>& arrD);


};