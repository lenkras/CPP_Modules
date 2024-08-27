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

	std::string getFirstName()const;
	std::string getLastName()const;
	std::string getNickname()const;
	std::string getPhoneNumber()const;
	std::string getSecret()const;
};

#endif