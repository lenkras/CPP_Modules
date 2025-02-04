/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 12:09:20 by epolkhov          #+#    #+#             */
/*   Updated: 2025-01-20 12:09:20 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
//#include "Array.tpp"

template <typename T>

class Array
{
	private:
		T* 				_array;
		unsigned int 	_len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		~Array();

		unsigned int size()const;
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

};

#include "Array.tpp"