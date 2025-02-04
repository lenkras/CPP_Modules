/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToBeDone.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 16:06:27 by epolkhov          #+#    #+#             */
/*   Updated: 2025-01-17 16:06:27 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>

void swap(T& a, T& b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>

T min(T& a, T& b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

template <typename T>

T max(T& a, T& b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
