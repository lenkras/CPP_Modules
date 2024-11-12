/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 14:14:39 by epolkhov          #+#    #+#             */
/*   Updated: 2024-11-08 14:14:39 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
		Bureaucrat me;
		std::cout<< "Me name: "<< me.getName()<< ", grade: "<< me.getGrade()<< std::endl;
		Bureaucrat you("Lena", 65);
		me = you;
		std::cout<< "Me name: "<< me.getName()<< ", grade: "<< me.getGrade()<< std::endl;

        Bureaucrat mike("Mike", 15);
        std::cout << mike << std::endl;

        mike.incrementGrade();
        std::cout << mike << std::endl;

		Bureaucrat bob("Bob", 150);
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;

    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}