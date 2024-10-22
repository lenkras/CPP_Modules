/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 14:54:56 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-15 14:54:56 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Unknown")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	this->type = copy.type;
	std::cout << "WrongAnimal copy constructor "<< type << " called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "WrongAnimal assignment operator called." << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal "<< type << " destructor called." << std::endl;
}

void WrongAnimal::makeSound()const
{
	std::cout << "WrongAnimal makes wrong sound."<< std::endl;
}

std::string WrongAnimal::getType()const
{
	return (this->type);
}


