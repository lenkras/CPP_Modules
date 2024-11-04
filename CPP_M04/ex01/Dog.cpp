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
	std::cout << "Dog default constructor created." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "Dog copy constructor is called." << std::endl;
	type = "Dog";
	brain = new Brain(*copy.brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete(brain);
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog assign operator is called."<< std::endl;
	if (this != &copy)
	{
		type = copy.type;
		*brain = *copy.brain;

	}
	return (*this);
}

void Dog::makeSound()const
{
	std::cout << "Woof Woof. I have a brain at "<< brain << std::endl;
}