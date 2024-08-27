/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-27 08:07:26 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-27 08:07:26 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string  name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif