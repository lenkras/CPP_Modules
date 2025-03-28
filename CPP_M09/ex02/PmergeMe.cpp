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
    for (size_t n : array) {
        std::cout << n << " ";
    }
     std::cout << std::endl;
	return true;
}

std::vector<size_t>& PmergeMe::getArray()
{
	return array;
}

std::deque<size_t>& PmergeMe::getDeque()
{
	return arrD;
}

static size_t jacobsthal(size_t k) // 1 1 3 5 11 21........
{
    if (k == 0) return 0;
    if (k == 1) return 1;

    size_t a = 0, b = 1;  // Initial values for J(0) and J(1)
    
    for (size_t i = 2; i <= k; ++i) {
        size_t temp = b;
        b = b + 2 * a;  // J(k) = J(k-1) + 2 * J(k-2)
        a = temp;  // Update J(k-2) for the next iteration
    }
    
    return b;
}

static std::vector<size_t> getInsertionSequence(size_t size)
{
    std::vector<size_t> sequence;
    size_t k = 2;
    while (true) 
    {
        size_t j = jacobsthal(k);
        size_t prev_j = jacobsthal(k-1);
            
         if (prev_j >= size)
            break;
            
        for (size_t i = j; i > prev_j; --i)
        {
            if (i <= size) {
                sequence.push_back(i);
            }
        }
        k++;
    }
    return sequence;
}

void PmergeMe::addToVector(const std::string& str)
{
	std::unordered_set<size_t> seen;
	auto startAdd = std::chrono::high_resolution_clock::now();
	std::stringstream ss(str);
    std::string temp;
    while (ss >> temp)
	{
        try {
            size_t num = std::stoi(temp);
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

std::vector<size_t> PmergeMe::fordJohnsonVector(std::vector<size_t>& array)
{
    if (array.size() <= 1) {
        return array;
    }
    std::vector<std::pair<size_t, size_t>> pairs;
    for (size_t i = 0; i < array.size() - 1; i += 2) 
    {
         if (array[i] < array[i + 1]) {
            pairs.push_back(std::make_pair(array[i], array[i + 1]));
        } else {
            pairs.push_back(std::make_pair(array[i + 1], array[i]));
        }
    }
    std::vector<size_t> larger_elements;
    for (const auto& pair : pairs)
    {
        larger_elements.push_back(pair.second);
    }
    larger_elements = fordJohnsonVector(larger_elements);
    std::vector<size_t> main_chain = larger_elements;
    if (!pairs.empty())
    {
        size_t b1 = pairs[0].first;
        for (const auto& pair: pairs)
        {
            if (pair.second == larger_elements[0])
            {
                b1 = pair.first;
                break;
            }
        }
            main_chain.insert(main_chain.begin(), b1);
    }
    std::vector<size_t> insertion_seq = getInsertionSequence(pairs.size());
    for (size_t i : insertion_seq)
    {
        if (i >= 2) 
        {
            size_t a_i = larger_elements[i-1];
            size_t b_i = 0;
            for(const auto& pair: pairs)
            {
                if (pair.second == a_i)
                {
                    b_i = pair.first;
                    break;
                }
            }
            auto pos = std::lower_bound(main_chain.begin(), 
                    main_chain.begin() + std::min(2 * i - 1, main_chain.size()), b_i); // Calculate insertion range (2i - 1 elements)
            main_chain.insert(pos, b_i);
        }
    }
	if (array.size() % 2 != 0)
	{
		size_t last_number = array.back();
		auto position = std::lower_bound(main_chain.begin(), main_chain.end(), last_number);
		main_chain.insert(position, last_number);
	}
    return main_chain;
}

void PmergeMe::addToDeque(const std::string& str)
{
	std::stringstream ss(str);
    auto startAdd = std::chrono::high_resolution_clock::now();
	std::string temp;
    while (ss >> temp)
	{
        size_t num = std::stoi(temp);
        arrD.push_back(num); 
    }
	auto endAdd = std::chrono::high_resolution_clock::now();
	timeAddDeque = std::chrono::duration_cast<std::chrono::microseconds>(endAdd - startAdd);

}

std::deque<size_t> PmergeMe::fordJohnsonDeque(std::deque<size_t> &array)
{
	if (array.size() <= 1)
		return array;
	std::deque<std::pair<size_t, size_t>> pairs;
	for (size_t i = 0; i < array.size() - 1; i += 2)
	{
		if (array[i] < array[i + 1])
			pairs.push_back(std::make_pair(array[i], array[i + 1]));
		else
			pairs.push_back(std::make_pair(array[i + 1], array[i]));
	}
	std::deque<size_t> large_numbers;
	for (const auto &pair : pairs)
	{
		large_numbers.push_back(pair.second);
	}
	large_numbers = fordJohnsonDeque(large_numbers);

	std::deque<size_t> sorted_array = large_numbers;

	if (!pairs.empty())
    {
        size_t b1 = pairs[0].first;
        for (const auto& pair: pairs)
         {
            if (pair.second == large_numbers[0])
            {
                 b1 = pair.first;
                break;
            }
        }
        sorted_array.insert(sorted_array.begin(), b1);
    }
		
    std::vector<size_t> insertion_seq = getInsertionSequence(pairs.size());
    for (size_t i : insertion_seq) 
    {
        if (i >= 2) 
        {
            size_t a_i = large_numbers[i-1];
            size_t b_i = 0;
            for(const auto& pair: pairs)
            {
                if (pair.second == a_i)
                {
                    b_i = pair.first;
                    break;
                }
            } 
            auto pos = std::lower_bound(sorted_array.begin(), 
                    sorted_array.begin() + std::min(2 * i - 1, sorted_array.size()), b_i);
            sorted_array.insert(pos, b_i);
        }
    }
	if (array.size() % 2 != 0)
	{
		size_t last_number = array.back();
		auto position = std::lower_bound(sorted_array.begin(), sorted_array.end(), last_number);
		sorted_array.insert(position, last_number);
	}
    return sorted_array;
	
}

void PmergeMe::sortAndprint(std::vector<size_t> &array, std::deque<size_t>& arrD)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<size_t> sortedArray = fordJohnsonVector(array);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "After: ";
	for (size_t num : sortedArray) {
        std::cout << num << " ";
    }
	std::cout<< std::endl;

	auto startD = std::chrono::high_resolution_clock::now();
	std::deque<size_t> sortedArrayD = fordJohnsonDeque(arrD);
	auto endD = std::chrono::high_resolution_clock::now();
	
	std::cout << std::fixed << std::setprecision(5);
	timeSortVector = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	auto duration = timeAddVector + timeSortVector;
    std::cout << "Time to process a range of " << array.size() 
              << " elements with std::vector: " << duration.count() << " us" << std::endl;
	
	timeSortDeque = std::chrono::duration_cast<std::chrono::microseconds>(endD - startD);
    auto durationDeq = timeAddDeque + timeSortDeque;
	std::cout << "Time to process a range of " << arrD.size() 
              << " elements with std::deque: " << durationDeq.count() << " us" << std::endl;
}
