/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-28 13:24:46 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-28 13:24:46 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created." << std::endl;
}

void Zombie:: announce()
{
	std::cout << "---------------------------" << std::endl;
	std::cout << name << ": BraiiiiiiiinnnzzzZ..." << std::endl;
	std::cout << "---------------------------" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed." << std::endl;
}

void Zombie:: setName(std::string name)
{
	this->name = name;
}
