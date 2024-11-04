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
	std::cout << "Cat default constructor created." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << "Cat copy constructor is called." << std::endl;
	type = "Cat";
	brain = new Brain(*copy.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete(brain);
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat assign operator is called."<< std::endl;
	if (this != &copy)
	{
		type = copy.type;
		*brain = *copy.brain;

	}
	return (*this);
}

void Cat::makeSound()const
{
	std::cout << "Mau Mau MIIIUUUU. I have brain at "<< brain << std::endl;
}