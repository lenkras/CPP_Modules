/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 11:15:07 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-15 11:15:07 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("UnknownFrag")
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout<< "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout<< "FragTrap " <<_name<< " constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap& copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called."<< std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " deleted."<< std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& copy)
{
	std::cout << "FragTrap assignment operator called."<< std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a positive high five!" << std::endl;
}