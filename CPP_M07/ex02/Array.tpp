/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 14:58:33 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-04 14:58:33 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(nullptr), _len(0){}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _len(n) {}

template <typename T>
Array<T>::Array(const Array& copy): _array(new T[copy._len]), _len(copy._len)
{
	for (size_t i = 0; i < _len; i++)
	{
		_array[i] = copy._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		delete[] _array;
		_array = new T[copy._len];
		_len = copy._len;
		for (size_t i = 0; i < _len; i++)
		{
			_array[i] = copy._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[]_array;
}

template <typename T>
unsigned int Array<T>::size()const
{
	return _len;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _len)
	{
		throw std::out_of_range("Index is out of range");
	}
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const // Read only, cannot modify the values in class
{
	if (index >= _len)
	{
		throw std::out_of_range("Index is out of range");
	}
	return _array[index];
}