/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 09:20:07 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-06 09:20:07 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): N(0), arr(0, 0){}

Span::Span(unsigned int N): N(N), arr(0, 0){}

const Span& Span::operator=(Span& copy)
{
	if (this != &copy)
	{
		N = copy.N;
		arr = copy.arr;
	}
	return *this;
}

Span::Span(Span& copy):N(copy.N), arr(copy.arr){}

Span::~Span(){}

void Span::addNumbers()
{
	for (size_t i = 0; i < N; i++)
	{
		int num = std::rand() % 100 + 1;
		addNumber(num);
	}
	// for (size_t i = 0; i < arr.size(); i++)
	// {
	// 	std::cout << "arr["<< i << "]"<< arr[i]<< std::endl;
	// }
}

void Span::addNumber(int number)
{
	if (arr.size() >= N)
	{
		throw std::out_of_range("Array is full, cannot add more numbers.");
	}
	arr.push_back(number);
}

int Span::shortestSpan()
{
	//std::cout << "Array size in shortest: "<< arr.size()<< std::endl;
	if (arr.size() <= 1)
	{
		throw std::logic_error("Size of array is too small to find the shortest span.");
	}
	std::vector<int> diff;
	for (size_t i = 0; i < arr.size() - 1; ++i)
	{
		for (size_t j = i + 1; j < arr.size(); ++j)
		{
			diff.push_back(std::abs(arr[i] - arr[j]));
		}
	}
	auto minSpan = std::min_element(diff.begin(), diff.end());
	return (*minSpan);
}

int Span::longestSpan()
{
	//std::cout << "Array size in longest: "<< arr.size()<< std::endl;
	if (arr.size() <= 1)
	{
		throw std::logic_error("Size of array is too small to find the longest span.");
	}
	std::vector<int> diff;
	for (size_t i = 0; i < arr.size() - 1; ++i)
	{
		for (size_t j = i + 1; j < arr.size(); ++j)
		{
			diff.push_back(std::abs(arr[i] - arr[j]));
		}
	}
	auto maxSpan = std::max_element(diff.begin(), diff.end());
	return (*maxSpan);
}