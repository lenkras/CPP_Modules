/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 14:34:57 by epolkhov          #+#    #+#             */
/*   Updated: 2024-12-03 14:34:57 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
	try {
        if (argc != 2) {
            throw std::invalid_argument("Invalid number of arguments.");
        }

        ScalarConverter::convert(argv[1]);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}