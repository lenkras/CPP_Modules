/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 10:36:50 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-09 10:36:50 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedInt;
		static const int _numBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& num);
		Fixed& operator=(const Fixed& num);
		Fixed(const int& integer_val);
		Fixed(const float& float_val);
		~Fixed();

		int getRawBits()const;
		void setRawBits(int const raw);
		float toFloat()const;
		int toInt()const;
};

std::ostream& operator<<(std::ostream &print, const Fixed &klass);

#endif