/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:15:04 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-26 11:15:04 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string PhoneBook::truncateString(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void PhoneBook::addContact()
{
	contacts[i].contactInfo();

	if (std::cin.eof())
		return ;
	if (i < 7)
		i = i + 1;
	else
		i = 0;
	std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::displayContacts()
{
	std::cout << "                 CONTACTS" << std::endl;
	std::cout << std::setw(10) << std::right << "Index" << "|"
			<< std::setw(10) << std::right << "First Name" << "|"
			<< std::setw(10) << std::right << "Last Name" << "|"
			<< std::setw(10) << std::right << "Nickname" << std::endl;

	for (int j{0}; j < 8; ++j)
	{
		if (contacts[j].getFirstName().empty())
			continue ;
		std::cout << std::setw(10) << std::right << j << "|"
				<< std::setw(10) << std::right << truncateString(contacts[j].getFirstName()) << "|"
				<< std::setw(10) << std::right << truncateString(contacts[j].getLastName()) << "|"
				<< std::setw(10) << std::right <<  truncateString(contacts[j].getNickname()) << std::endl;
	}
}

void PhoneBook::searchContact()
{
	if (contacts[0].getFirstName().empty())
	{
		std::cout << "No contacts available." << "\n";
		return ;
	}
	displayContacts();
	while (true)
	{
		std::cout << std::endl;
		std::cout << "Enter the index of the contact you want to search or -1 to exit." << std::endl;
		int index;
		std::cin >> index;
		if (std::cin.eof())
			break ;
		if (!std::cin >> index)
		{
			std::cout << "Invalid index." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue ;
		}
		if (index >= 0 && index <= 7 && !contacts[index].getFirstName().empty())
		{
			std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
            std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
            std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contacts[index].getSecret() << std::endl;
			break ;
		}
		else if (index == -1)
			break ;
		else
			std::cout << "Invalid index." << std::endl;
			
	}
	std::cin.ignore();
}
