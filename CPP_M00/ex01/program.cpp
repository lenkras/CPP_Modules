/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:16:10 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-26 11:16:10 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook 	phoneBook;
	std::string input;

	while (true)
	{
		if (std::cin.eof())
			break ;
		std::cout << "Enter a command(ADD, SEARCH or EXIT): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << "\n";
	}
	return (0);
}