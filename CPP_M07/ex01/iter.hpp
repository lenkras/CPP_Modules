/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 09:28:38 by epolkhov          #+#    #+#             */
/*   Updated: 2025-01-20 09:28:38 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>

void iter(T* arr, size_t len, void (*fun)(T&))
{
	for (size_t i = 0; i < len; i++)
	{
		fun(arr[i]);
	}
}

void plusFloat(float& num)
{
	num += 2.5f;
}

void printHello(std::string& str)
{
	str += " hello";
}