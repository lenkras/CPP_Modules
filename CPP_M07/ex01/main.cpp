/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 10:20:09 by epolkhov          #+#    #+#             */
/*   Updated: 2025-01-20 10:20:09 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	float arr[] = {1.2f, 2.5f, 3.5f, 4.5f};
	std::cout << "Original float array: ";
    for (size_t i = 0; i < 4; ++i) {
        std::cout << arr[i] << " ";
    }
	iter(arr, 4, plusFloat);

	std::cout << "Modified float array: ";
    for (size_t i = 0; i < 4; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

	
	std::string str[] = {"World", "Girl", "Me"};
	std::cout << "Original string array: ";
    for (size_t i = 0; i < 3; ++i) {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;
	iter(str, 3, printHello);

	std::cout << "Modified string array: ";
    for (size_t i = 0; i < 3; ++i) {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;
	return 0;
}
