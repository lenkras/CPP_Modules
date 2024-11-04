/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 09:53:35 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-29 09:53:35 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria():_type("Unknown")
{
	//std::cout<< "AMateria default constructor called."<< std::endl;
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
	//std::cout<< "AMateria of " << _type << " called."<<std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	_type = copy._type;
	//std::cout << "Copy constructor for AMateria " << _type << " called."<< std::endl;
}

AMateria& AMateria::operator=(const AMateria& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	//std::cout << "AMateria assignment operator called." << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "AMateria "<< _type << " destructor called." << std::endl;
}

std::string const &AMateria::getType()const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout<< "AMateria called to use character "<< target.getName() << std::endl;
}
