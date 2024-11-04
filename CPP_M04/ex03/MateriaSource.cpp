/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 14:29:39 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-29 14:29:39 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout<< "MateriaSource default constructor callled." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		materias[i] = nullptr;
	}
}

MateriaSource::~MateriaSource()
{
	//std::cout <<"MateriaSource destructor called."<< std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete materias[i];
		materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.materias[i])
		{
			delete(materias[i]);
			materias[i] = copy.materias[i]->clone();
		}
		else
		{
			materias[i] = nullptr;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			delete materias[i];
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

void MateriaSource::learnMateria(AMateria* type)
{
	if (type)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!materias[i])
			{
				materias[i] = type;
				std::cout<< "MateriaSource: Learned materia of type: " << materias[i]->getType()<< std::endl;
				return ;
			}
		}
		std::cout << "MateriaSource: Cannot learn more than 4 materias." << std::endl;
		delete type;
		type = nullptr;
	}
	else
	{
		std::cout<< "MateriaSource does not exist."<< std::endl;
		return ;
	}
	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i= 0; i < 4; i++)
	{
		if (materias[i])
		{
			if (materias[i]->getType() == type)
			{
				return(materias[i]->clone());
			}
		}
	}
	std::cout<< "MateriaSource: Materia of type "<< type << " not found and cannot be created."<< std::endl;
	return (nullptr);
}