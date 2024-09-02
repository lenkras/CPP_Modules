/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-02 10:33:31 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-02 10:33:31 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl start;

	if (argc == 2)
		start.complain(argv[1]);
	else
	{	
		std::cout << "Invalid number of arguments." << std::endl;
		return (1);
	}
	return (0);
}
