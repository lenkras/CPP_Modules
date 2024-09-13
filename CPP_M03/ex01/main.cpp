/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-11 11:03:36 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-11 11:03:36 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "Creating ClapTrap..." << std::endl;
    ClapTrap clap("Clappy");

    // Test attack method of ClapTrap
    clap.attack("Target 1");
	clap.takeDamage(2);
	clap.takeDamage(5);

	clap.beRepaired(3);


    // Test creation of ScavTrap
    std::cout << "\nCreating ScavTrap..." << std::endl;
    ScavTrap scav("Scavvy");

    // Test attack method of ScavTrap (overridden)
    scav.attack("Target 2");
	scav.takeDamage(20);
	scav.takeDamage(5);

	scav.beRepaired(3);

    // Test ScavTrap special ability
    scav.guardGate();

    std::cout << "\nExiting program, destructors will be called..." << std::endl;

	return (0);
}