/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 15:22:51 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-29 15:22:51 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("Unknown")
{
	//std::cout << "Charcter default constructor called."<< std::endl;
	for (int i = 0; i < 4; i++)
	{
		materias[i] =  nullptr;
	}
}
Character::Character(const std::string& name)
{
	//std::cout << "Character parameterized constructr called." << std::endl;
	_name =  name;
	for (int i = 0; i < 4; i++)
	{
		materias[i] =  nullptr;
	}
}

Character::Character(const Character& copy)
{
	//std::cout << "Character Copy constructor called"<< std::endl;
	_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy.materias[i])
		{
			materias[i] = copy.materias[i]->clone();
		}
		else
		{
			materias[i] = nullptr;
		}
	}
}

Character& Character::operator=(const Character& copy)
{
	//std::cout<< "Character assign operator called." << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			delete materias[i];
		}
		_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			if (copy.materias[i])
			{
				materias[i] = copy.materias[i]->clone();
			}	
			else
			{
				materias[i] = nullptr;
			}
		}
	}
	return (*this);
}

Character::~Character()
{
	//std::cout<< "Character destructor called."<< std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete materias[i];
		materias[i] = nullptr;
	}
}

std::string const& Character::getName()const
{
	return(_name);
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (!materias[i])
			{
				materias[i] = m;
				return ;
			} 
			else if (i == 3)
			{
				std::cout << "Character: Inventory full! Cannot equip more materias." << std::endl;
			}
		}
	} 
	else
	{
		std::cout << "Character: Cannot equip a nullptr materia." << std::endl;
		return ;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (materias[idx])
		{
			delete materias[idx];
			materias[idx] = nullptr;
		}
		else{
			std::cout << "No materia to unequip at index " << idx << "." << std::endl;
		}
	}
	else{
		std::cout << "Invalid index for unequip." << std::endl;
		return ;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (materias[idx])
		{
			materias[idx]->use(target);
		}
		else{
			std::cout << "No materia equipped at index " << idx << "." << std::endl;
		}
	}
	else{
		 std::cout << "Invalid index for use." << std::endl;
		 return ;
	}
}

