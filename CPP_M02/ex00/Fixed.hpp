/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-05 10:42:45 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-05 10:42:45 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int _fixedInt;
		static const int _numBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& num);
		Fixed& operator=(const Fixed& num);
		~Fixed();

		int getRawBits()const;
		void setRawBits(int const raw);
};

#endif