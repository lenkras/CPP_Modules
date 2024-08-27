/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:15:36 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-26 11:15:36 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::contactInfo()
{
	while (true)
	{
		std::cout << "Enter First Name: ";
		std::getline(std::cin, first_name);
		if (std::cin.eof())
			return ; 
		if (first_name.empty())
			std::cout << "Input can not be empty."<< "\n";
		else
			break ;
	}
	while (true)
	{
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, last_name);
		if (std::cin.eof())
			return ; 
		if (last_name.empty())
			std::cout << "Input can not be empty."<< "\n";
		else
			break ;
	}
	while (true)
	{
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			return ; 
		if (nickname.empty())
			std::cout << "Input can not be empty."<< "\n";
		else
			break ;
	}
	while (true)
	{
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, phone_number);
		if (std::cin.eof())
			return ; 
		bool isValid = true;
		for (char ch: phone_number)
		{
			if (!std::isdigit(ch))
			{
				isValid = false;
				break ;
			}
		}
		if (phone_number.empty())
			std::cout << "Input can not be empty."<< "\n";
		else if (!isValid)
			std::cout << "Phone Number must contain only digits." << std::endl;
		else
			break ;
	}
	while (true)
	{
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, darkest_secret);
		if (std::cin.eof())
			return ; 
		if (darkest_secret.empty())
			std::cout << "Input can not be empty."<< "\n";
		else
			break ;
	}
}