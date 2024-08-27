/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-27 10:24:34 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-27 10:24:34 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

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

#endif