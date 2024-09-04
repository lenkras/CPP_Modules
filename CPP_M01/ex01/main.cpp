/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-28 13:24:00 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-28 13:24:00 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <cctype>

// int main()
// {
// 	//int N = 5;
// 	int N = 10;
// 	// int N = 2;

// 	Zombie *horde;
// 	horde = zombieHorde(N, "Beee");
// 	for (int i = 0; i < N; ++i)
// 		horde[i].announce();
// 	delete[] horde;
	
// 	return (0);
// }

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		std::string s = argv[1];
		for (char c: s)
		{
			if (std::isdigit(c))
			{
				int N;
				N = std::stoi(argv[1]);
				Zombie *horde;
				horde = zombieHorde(N, argv[2]);
				for (int i = 0; i < N; ++i)
					horde[i].announce();
				delete[] horde;
			}
			else
			{
				std::cerr<< "First argument should be an integer."<< std::endl;
				return (1);
			}
		}
	}
	else
	{
		std::cerr<< "Invalid number of arguments."<< std::endl;
	}
	return (0);
}