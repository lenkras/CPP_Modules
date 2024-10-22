/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 13:52:42 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-15 13:52:42 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor created." << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	type = "Dog";
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog assign operator called."<< std::endl;
	if (this != &copy)
		type = copy.type;
	return (*this);
}

void Dog::makeSound()const
{
	std::cout << "Woof Woof"<< std::endl;
}