/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 10:36:42 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-09 10:36:42 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixedInt(0)
{
	std::cout << "Default constructor called."<< std::endl;
}

Fixed::Fixed(const Fixed& num)
{
	*this = num;
	std::cout << "Copy constructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& num)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &num)
		this->_fixedInt = num.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits()const
{
	//std::cout << "getRawBits member function called." << std::endl;
	return (this->_fixedInt);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedInt = raw;
	//std::cout << "setRawBits member function called." << std::endl;
}

Fixed::Fixed(const int& integer_val)
{
	std::cout << "Int constructor called." << std::endl;
	_fixedInt = integer_val << _numBits;

}
Fixed::Fixed(const float& float_val)
{
	std::cout << "Float constructor called." << std::endl;
	_fixedInt = roundf(float_val * (1 << _numBits));
}

int Fixed::toInt()const
{
	int result = this->getRawBits() >> _numBits;
	return (result);
}

float Fixed::toFloat()const
{
	float result = static_cast<float>(this->getRawBits()) / (1 << _numBits);
	return (result);
}

std::ostream& operator<<(std::ostream &print, const Fixed &klass)
{
	print << klass.toFloat();
	return (print);
}


