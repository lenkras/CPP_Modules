/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 09:19:57 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-06 09:19:57 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <climits>

class Span
{
	private:
		unsigned int N;
		std::vector<int> arr;
	public:
		Span();
		Span(unsigned int N);
		Span(Span& copy);
		const Span& operator=(Span& );
		~Span();

		void addNumber(int number);
		void addNumbers();
		int shortestSpan();
		int longestSpan();
};