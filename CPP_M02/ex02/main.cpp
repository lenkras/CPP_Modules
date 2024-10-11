/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-10 13:12:42 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-10 13:12:42 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "print a: "<< a << std::endl;
	std::cout <<"Pre-Increment: "<<  ++a << std::endl;
	std::cout << "print a"<< a << std::endl;
	std::cout << "Post-increment: "<< a++ << std::endl;
	std::cout << "Post- Decriment: "<< a-- << std::endl;
	std::cout << "Print a: "<< a << std::endl;
	std::cout << "Print b: " << b << std::endl;
	std::cout << "Comparison: " << (a > b) << std::endl;
	std::cout << "Addition: " << (a + b) << std::endl;
	std::cout << "Multiply: " << (a * b) << std::endl;
	std::cout << "Print max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "Print min: " << Fixed::min( a, b ) << std::endl;
	return 0;
}