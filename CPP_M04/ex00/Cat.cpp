/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 14:03:37 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-15 14:03:37 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor created." << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	type = "Cat";
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat assign operator called."<< std::endl;
	if (this != &copy)
		type = copy.type;
	return (*this);
}

void Cat::makeSound()const
{
	std::cout << "Mau Mau MIIIUUUU"<< std::endl;
}