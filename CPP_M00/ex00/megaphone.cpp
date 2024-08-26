/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:13:50 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-26 11:13:50 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	else
	{
		for (int i{1}; i < argc; i++)
		{
			for (int j{0}; argv[i][j] > 0; j++)
				std::cout << (char)std:: toupper(argv[i][j]);
			std::cout << " ";
		}
		std::cout << std:: endl;
	}
	return (0);
}
