/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-11 07:56:35 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-11 07:56:35 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name("Unknown"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
	this->_name = name;
	this->_hitPoint = 10;
	this->_energyPoint = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap parameterized constructor called for "<< this->_name << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& copy): _name(copy._name), _hitPoint(copy._hitPoint),
 _energyPoint(copy._energyPoint), _attackDamage(copy._attackDamage)
{
	std::cout << "CllapTrap copy constructor called for " << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy assignment operator called."<< std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoint = copy._hitPoint;
		this->_energyPoint = copy._energyPoint;
		this->_attackDamage = copy._attackDamage;
	}
	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target_name)
{
	if (this->_hitPoint != 0 && this->_energyPoint != 0)
	{
		this->_energyPoint--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target_name << " , causing " << this->_attackDamage << " points of damage." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap can not attack " << target_name << ". No hit points or energy points left." << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint == 0 || this->_energyPoint == 0)
	{
		std::cout << "CrapTrap " << this->_name<< " can not do repair because of running out of energy points or hit points." << std::endl;
		return ;
	}
	this->_hitPoint += amount;
	this->_energyPoint--;
	std::cout << "ClapTrap " << this->_name << " repaired and received " << amount << " hit points. Hit poins remain: " << this->_hitPoint << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint == 0 || this->_energyPoint == 0)
		std::cout << "CrapTrap " << this->_name<< " can not take demage because of run out of energy points or hit points." << std::endl;
	if (amount >= static_cast<unsigned int>(this->_hitPoint))
	{
		this->_hitPoint = 0;
		std::cout << "ClapTrap " << this->_name << " takes "<< amount << " points of damage and is destroyed." << std::endl;
	}
	else
	{
		this->_hitPoint -= amount;
		std::cout << "ClapTrap "<< this->_name << " takes " << amount << " points of damage. Hit points remain: " << this->_hitPoint << std::endl;

	}
}

