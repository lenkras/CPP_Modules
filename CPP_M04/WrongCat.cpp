/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 15:02:17 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-15 15:02:17 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat default contructor is called."<< std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other): WrongAnimal(other)
{
	std::cout << "WrongCat copy contructor is called."<< std::endl;
	type = "WrongCat";
}

WrongCat & WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assign operator is called." << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "RRRRRRRaaaaaWWWW" << std::endl;
}