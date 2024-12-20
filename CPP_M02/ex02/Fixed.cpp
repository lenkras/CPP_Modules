/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-10 13:12:49 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-10 13:12:49 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixedInt(0){}

Fixed::Fixed(const Fixed& num)
{
	*this = num;
}

Fixed& Fixed::operator=(const Fixed& num)
{
	if (this != &num)
		this->_fixedInt = num.getRawBits();
	return (*this);
}

Fixed::~Fixed(){}

int Fixed::getRawBits()const
{
	return (this->_fixedInt);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedInt = raw;
}

Fixed::Fixed(const int& integer_val)
{
	_fixedInt = integer_val << _numBits;
}
Fixed::Fixed(const float& float_val)
{
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

bool Fixed::operator>(const Fixed& num)const
{
	if (_fixedInt > num._fixedInt)
		return (true);
	else
		return (false);
}

bool Fixed:: operator<(const Fixed& num)const
{
	if (_fixedInt < num._fixedInt)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed& num)const
{
	if(_fixedInt <= num._fixedInt)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed& num)const
{
	if(_fixedInt >= num._fixedInt)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed& num)const
{
	if(_fixedInt == num._fixedInt)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed& num)const
{
	if(_fixedInt != num._fixedInt)
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(const Fixed& num)const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + num.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& num)const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - num.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed& num)const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * num.getRawBits()) >> _numBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& num)const
{
	Fixed result;
	result.setRawBits((this->getRawBits() << _numBits) / num.getRawBits());
	return (result);
}

Fixed& Fixed::operator++()
{
	this->_fixedInt += 1;
	return(*this);
}

Fixed& Fixed::operator--()
{
	this->_fixedInt -= 1;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedInt += 1;
	return(temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedInt -= 1;
	return(temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
		return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else
		return(b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return(b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	else
		return(b);
}
