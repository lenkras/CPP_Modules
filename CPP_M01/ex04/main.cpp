/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-30 10:34:41 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-30 10:34:41 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcess.hpp"


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (1);
	}
	else
	{
		if (*argv[2] == '\0' || *argv[3] == '\0')
		{
			std::cerr << "Error: input can not be empty." << std::endl;
			return (1);
		}
	}
	FileProcess process(argv[1], argv[2], argv[3]);
	process.processFile();

	return (0);
}