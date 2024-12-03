/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-02 15:13:53 by epolkhov          #+#    #+#             */
/*   Updated: 2024-12-02 15:13:53 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

struct CreateForm
{
	std::string name;
	AForm* (*createForm)(const std::string& target);
};

AForm* createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* createPresidentForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

Intern::Intern()
{
	std::cout<< "Intern default constructor called."<< std::endl;
}

Intern::~Intern()
{
	std::cout<< "Intern destructor called."<< std::endl;
}

Intern::Intern(Intern& )
{
	std::cout<< "Intern copy constructor called."<< std::endl;
}

Intern& Intern::operator=(Intern& copy)
{
	if (this != &copy) {}
	return *this;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	static const CreateForm formMakers[] = {
		{"robotomy request", createRobotomyForm},
		{"shrubbery creation", createShrubberyForm},
		{"presidential pardon", createPresidentForm}

	};

	for (int i = 0; i < 3; ++i)
	{
		if (name == formMakers[i].name)
		{
			AForm* form = formMakers[i].createForm(target);
			std::cout << "Intern creates form: "<< form->getName()<< std::endl;
			return form;
		}
	}
	throw std::invalid_argument("Unknown form name: " + name);
}