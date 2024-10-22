/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-16 15:04:22 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-16 15:04:22 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called."<< std::endl;
}

Brain::Brain(Brain& copy)
{
	std::cout << "Brain copy constructor called."<< std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& curr)
{
	std::cout << "Brain assign operator called."<< std::endl;
	if (this != &curr)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = curr.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called."<< std::endl;
}