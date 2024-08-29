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

int main()
{
	//int N = 5;
	int N = 10;
	// int N = 2;

	Zombie *horde;
	horde = zombieHorde(N, "Beee");
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	delete[] horde;
	
	return (0);
}