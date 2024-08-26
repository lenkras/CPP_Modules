/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 11:16:47 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-26 11:16:47 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>

class Contact {
private:	
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	void contactInfo();

	std::string getFirstName()const
	{
		return (first_name);
	}
	std::string getLastName()const
	{
		return (last_name);
	}
	std::string getNickname()const
	{
		return (nickname);
	}
	std::string getPhoneNumber()const
	{
		return (phone_number);
	}
	std::string getSecret()const
	{
		return (darkest_secret);
	}
};

class PhoneBook {
private:
	Contact contacts[8];
	int	i {0};

	std::string truncateString(const std::string& str);
public:
	void addContact();
	void displayContacts();
	void searchContact();
};

#endif