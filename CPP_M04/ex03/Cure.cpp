/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 13:49:18 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-29 13:49:18 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
	//std::cout << "Default constructor for Cure called."<< std::endl;
}

Cure::Cure(const Cure& copy):AMateria(copy)
{ 
	//std::cout<< "Cure copy constructor callled for type: "<< _type<< std::endl;
}

Cure::~Cure()
{
	//std::cout << "Cure destructor called for type: "<< _type<< std::endl;
}

Cure& Cure::operator=(const Cure& copy)
{
	if (this != &copy){
		AMateria::operator=(copy);
	}
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout<< "* heals  "<< target.getName() << "'s wounds *"<< std::endl;
}

Cure* Cure::clone()const
{
	//std::cout<< "Cure clone called for type: "<<_type<< std::endl;
	Cure *newCure = new Cure();
	return(newCure);
}
