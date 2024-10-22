/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 12:50:30 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-15 12:50:30 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Unknown")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const std::string& type)
{
	this->type = type;
	std::cout << "Animal parameterized costructor " << type << " called." << std::endl;
}

Animal::Animal(const Animal& copy)
{
	this->type = copy.type;
	std::cout << "Animal copy constructor "<< type << " called." << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "Animal assignment operator called." << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal "<< type << " destructor called." << std::endl;
}

std::string Animal::getType()const
{
	return (this->type);
}
