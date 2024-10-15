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
#include "FragTrap.hpp"

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

    std::cout << "Creating FragTrap named 'Fraggy'..." << std::endl;
    FragTrap frag1("Fraggy");

    std::cout << "\nCreating a copy of Fraggy called 'FraggyClone'..." << std::endl;
    FragTrap frag2(frag1); // Copy constructor
    frag2.attack("svoboda");
    frag2.takeDamage(15);
    frag2.beRepaired(3);

    std::cout << "\nFraggyClone requests a high five:" << std::endl;
    frag2.highFivesGuys();

    std::cout << "\nAssignment operation of FraggyClone to a new FragTrap 'FraggyClone2'..." << std::endl;
    FragTrap frag3;
    frag3 = frag2; // Copy assignment

    std::cout << "\nFraggyClone2 requests a high five:" << std::endl;
    frag3.highFivesGuys();

    std::cout << "\nExiting program..." << std::endl;
   
	return (0);
}