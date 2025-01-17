/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 10:22:05 by epolkhov          #+#    #+#             */
/*   Updated: 2025-01-07 10:22:05 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data value = {6};

	uintptr_t num = Serializer::serialize(&value);
	std::cout<< "Serialized value as a number: "<< num<< std::endl;
	Data *ptr = Serializer::deserialize(num);
	std::cout << "Original pointer: " << &value << std::endl;
	std::cout << "Deserialized pointer: " << ptr << std::endl;
	std::cout<< "Deserialized number as a pointer: "<< ptr->input<< std::endl;

	if (&value == ptr){
		std::cout << "Success: The pointers are the same!" << std::endl;
	}
	else{
		 std::cout << "Failure: The pointers are not the same." << std::endl;
	}
}