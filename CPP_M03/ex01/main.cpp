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

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1;
	ClapTrap clap2("Mau");
	ClapTrap clap3(clap2);

	clap1 = clap2;
	clap1.attack("WOOO");
	clap1.takeDamage(2);
	clap1.takeDamage(5);

	clap1.beRepaired(3);

	for (int i = 0; i < 10; ++i) {
        clap1.attack("AAAAHH");
    }

	clap1.takeDamage(20);
	clap1.beRepaired(10);

	clap1.attack("Final Target");
    clap1.beRepaired(1);
	return (0);
}