/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CllapTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-11 07:44:27 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-11 07:44:27 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoint;
		int _energyPoint;
		int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);
		~ClapTrap();

		void attack(const std::string& target_name);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif