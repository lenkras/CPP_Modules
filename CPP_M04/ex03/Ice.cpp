/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 13:20:06 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-29 13:20:06 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
	//std::cout << "Default constructor for Ice called."<< std::endl;
}

Ice::Ice(const Ice& copy):AMateria(copy)
{ 
	//std::cout<< "Ice copy constructor callled for type: "<< _type<< std::endl;
}

Ice::~Ice()
{
	//std::cout << "Ice destructor called for type: "<< _type<< std::endl;
}

Ice& Ice::operator=(const Ice& copy)
{
	if (this != &copy){
		AMateria::operator=(copy);
	}
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout<< "* shoots an ice bolt at "<< target.getName()<< " *"<< std::endl;
}

Ice* Ice::clone()const
{
	//std::cout<< "Ice clone called for type: "<<_type<< std::endl;
	Ice *newIce = new Ice();
	return(newIce);
}