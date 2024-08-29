/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-27 10:56:11 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-27 10:56:11 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *heapZomb = newZombie("BumHeap");
	heapZomb->announce();

	Zombie stackZomb("BabamStack");
	stackZomb.announce();
	
	randomChump("BamChump");
	delete(heapZomb);
	return(0);
}
