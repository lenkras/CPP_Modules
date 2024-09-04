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

// int main()
// {
// 	Zombie *heapZomb = newZombie("BumHeap");
// 	heapZomb->announce();

// 	Zombie stackZomb("BabamStack");
// 	stackZomb.announce();
	
// 	randomChump("BamChump");
// 	delete(heapZomb);
// 	return(0);
// }

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::cout << "-------New Zombie created on heap-------" << std::endl;
		Zombie *heapZomb = newZombie(argv[1]);
		heapZomb->announce();

		std::cout << "--------New Zombie cteated on stack--------" << std::endl;
		Zombie stackZomb(argv[1]);
		stackZomb.announce();
	
		std::cout << "--------Use of randomChump---------"<<std::endl;
		randomChump(argv[1]);
		std::cout << "Deleting heap-allocated Zombie." << std::endl;
    	delete heapZomb;
	}
	else
	{
		std::cerr<< "Invalid number of arguments." << std::endl;
		return (1);
	}
	return(0);
}