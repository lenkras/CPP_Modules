/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 12:08:21 by epolkhov          #+#    #+#             */
/*   Updated: 2025-01-20 12:08:21 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
		Array<int> intArray(5);

        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i + 20;
        }
        std::cout << "Int Array:" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl << std::endl;

        std::cout << "OUT OF BOUNDS" << std::endl;
        try {
            std::cout << intArray[7] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what()  << std::endl << std::endl;
        }

        std::cout << "COPY CONSTRUCTOR" << std::endl;
        Array<int> copyArray(intArray);
        copyArray[0] = 42;

        std::cout << "Copy Array:" << std::endl;
        for (unsigned int i = 0; i < copyArray.size(); i++) {
            std::cout << copyArray[i] << " ";
        }
        std::cout << std::endl << std::endl;

        std::cout << "Original Array after copy:" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl << std::endl;

		const Array<int>& constArr = intArray;
    	std::cout << "Elements of const array:" << std::endl;
    	for (unsigned int i = 0; i < constArr.size(); i++) 
		{
        	std::cout << constArr[i] << " "; // Reading elements from const array
    	}
    	std::cout << std::endl;

    	// Uncomment the following line to test the immutability of const operator[]
		 //constArr[0] = 100; // This will give a compilation error

		Array<int>& nonconstArr = intArray;
		nonconstArr[0] = 100;
    	std::cout << "Elements of nonconst array:" << std::endl;
    	for (unsigned int i = 0; i < nonconstArr.size(); i++) 
		{
        	std::cout << constArr[i] << " "; // Reading elements from const array
    	}
    	std::cout << std::endl;

}
    