/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 09:19:39 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-06 09:19:39 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::srand(std::time(nullptr));

	Span sp(5);
	try{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//sp.addNumber(15);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	} catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

	Span arr(15);
	arr.addNumbers();

	std::cout << arr.shortestSpan() << std::endl;
	std::cout << arr.longestSpan() << std::endl;

	Span minArr(1);

	minArr.addNumbers();
	 try {
        std::cout << "Shortest Span in 'minArr': " << minArr.shortestSpan() << std::endl;
        std::cout << "Longest Span in 'minArr': " << minArr.longestSpan() << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Error calculating span for minArr: " << e.what() << std::endl;
    }

}