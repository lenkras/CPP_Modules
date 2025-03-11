/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-04 10:39:46 by epolkhov          #+#    #+#             */
/*   Updated: 2025-03-04 10:39:46 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool PmergeMe::check_input(const std::string &str)
{
	if (str.empty()) 
	{
    	std::cerr << "Error: Empty input!" << std::endl;
   		return false;
	}
	for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i]) && str[i] != ' ') {
            throw std::invalid_argument("Error: Invalid character found in input.");
        }
    }
	addToVector(str);
	addToDeque(str);
    std::cout << "Before: ";
    for (int n : array) {
        std::cout << n << " ";
    }
     std::cout << std::endl;
	return true;
}

std::vector<int>& PmergeMe::getArray()
{
	return array;
}

std::deque<int>& PmergeMe::getDeque()
{
	return arrD;
}

void PmergeMe::addToVector(const std::string& str)
{
	std::unordered_set<int> seen;
	auto startAdd = std::chrono::high_resolution_clock::now();
	std::stringstream ss(str);
    std::string temp;
    while (ss >> temp)
	{
        try {
            int num = std::stoi(temp);
            if (seen.find(num) != seen.end()) {
                throw std::invalid_argument("Error: duplicates are not allowed.");
            }
            seen.insert(num);
            array.push_back(num);
        } catch (const std::out_of_range &e) {
            throw std::overflow_error("Error: number is too large or too small.");
        }
    }
	auto endAdd = std::chrono::high_resolution_clock::now();
	timeAddVector = std::chrono::duration_cast<std::chrono::microseconds>(endAdd - startAdd);

}

void PmergeMe::addToDeque(const std::string& str)
{
	std::stringstream ss(str);
    auto startAdd = std::chrono::high_resolution_clock::now();
	std::string temp;
    while (ss >> temp)
	{
        int num = std::stoi(temp);
        arrD.push_back(num); 
    }
	auto endAdd = std::chrono::high_resolution_clock::now();
	timeAddDeque = std::chrono::duration_cast<std::chrono::microseconds>(endAdd - startAdd);

}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> &array)
{
	if (array.size() <= 1)
		return array;
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < array.size() - 1; i += 2)
	{
		if (array[i] < array[i + 1])
			pairs.push_back(std::make_pair(array[i], array[i + 1]));
		else
			pairs.push_back(std::make_pair(array[i + 1], array[i]));
	}
	std::deque<int> large_numbers;
	for (const auto &pair : pairs)
	{
		large_numbers.push_back(pair.second);
	}
	large_numbers = fordJohnsonDeque(large_numbers);

	std::deque<int> sorted_array = large_numbers;
	for (const auto &pair : pairs)
	{
		int small_number = pair.first;
		auto position = std::lower_bound(sorted_array.begin(), sorted_array.end(), small_number);
		sorted_array.insert(position, small_number);
	}

	if (array.size() % 2 != 0)
	{
		int last_number = array.back();
		auto position = std::lower_bound(sorted_array.begin(), sorted_array.end(), last_number);
		sorted_array.insert(position, last_number);
	}
	
	return sorted_array;
}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> &array)
{
	if (array.size() <= 1)
		return array;
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < array.size() - 1; i += 2)
	{
		if (array[i] < array[i + 1])
			pairs.push_back(std::make_pair(array[i], array[i + 1]));
		else
			pairs.push_back(std::make_pair(array[i + 1], array[i]));
	}
	std::vector<int> large_numbers;
	for (const auto &pair : pairs)
	{
		large_numbers.push_back(pair.second);
	}
	large_numbers = fordJohnsonVector(large_numbers);

	std::vector<int> sorted_array = large_numbers;
	for (const auto &pair : pairs)
	{
		int small_number = pair.first;
		auto position = std::lower_bound(sorted_array.begin(), sorted_array.end(), small_number);
		sorted_array.insert(position, small_number);
	}

	if (array.size() % 2 != 0)
	{
		int last_number = array.back();
		auto position = std::lower_bound(sorted_array.begin(), sorted_array.end(), last_number);
		sorted_array.insert(position, last_number);
	}
	
	return sorted_array;
}

void PmergeMe::sortAndprint(std::vector<int> &array, std::deque<int>& arrD)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<int> sortedArray = fordJohnsonVector(array);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "After: ";
	for (int num : sortedArray) {
        std::cout << num << " ";
    }
	std::cout<< std::endl;

	auto startD = std::chrono::high_resolution_clock::now();
	std::deque<int> sortedArrayD = fordJohnsonDeque(arrD);
	auto endD = std::chrono::high_resolution_clock::now();
	
	std::cout << std::fixed << std::setprecision(5);
	timeSortVector = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	auto duration = timeAddVector + timeSortVector;
    std::cout << "Time to process a range of " << array.size() 
              << " elements with std::vector: " << duration.count() / 1000.0 << " us" << std::endl;
	
	timeSortDeque = std::chrono::duration_cast<std::chrono::microseconds>(endD - startD);
    auto durationDeq = timeAddDeque + timeSortDeque;
	std::cout << "Time to process a range of " << arrD.size() 
              << " elements with std::deque: " << durationDeq.count() / 1000.0 << " us" << std::endl;
}

