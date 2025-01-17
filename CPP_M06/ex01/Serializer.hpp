/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 10:26:46 by epolkhov          #+#    #+#             */
/*   Updated: 2025-01-07 10:26:46 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <cstdint>
#include <iostream>

struct Data
{
	int input;
};

class Serializer
{
	public:
		Serializer() = delete;
		Serializer(Serializer& copy) = delete;
		~Serializer()= delete;
		Serializer& operator=(Serializer& ) = delete;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif