/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-02 10:33:54 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-02 10:33:54 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<< std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now."<< std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*funcToComplain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			std::cout << "----------" << levels[i] << "----------" << std::endl;
			std::cout << std::endl;
			(this->*funcToComplain[i])();
			std::cout << std::endl;
			return ;
		}
	}
	std::cout << "!!!!I HAVE NO IDEA WHAT THE COMPAIN IS ABOUT!!!!" << std::endl;
}
