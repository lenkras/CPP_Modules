/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-11 13:10:12 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-11 13:10:12 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("UnknownScav")
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout<< "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout<< "ScavTrap " <<_name<< " constructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& copy): ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called."<< std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " deleted."<< std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& copy)
{
	std::cout << "ScavTrap assignment operator called."<< std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return (*this);
}

void ScavTrap::attack(const std::string& target_name)
{
	if (this->_hitPoint != 0 && this->_energyPoint != 0)
	{
		this->_energyPoint--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target_name << " , causing " << this->_attackDamage << " points of damage." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap can not attack " << target_name << ". No hit points or energy points left." << std::endl;
		return ;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode."<< std::endl;
}
