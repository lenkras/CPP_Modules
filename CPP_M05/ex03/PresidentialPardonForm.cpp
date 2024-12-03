/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 11:06:09 by epolkhov          #+#    #+#             */
/*   Updated: 2024-11-25 11:06:09 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Pardon", "Pardon Form default", 25, 5)
{
	std::cout<< "Pardon Form default constructor called."<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Pardon Form", target, 25, 5)
{
	std::cout<< "Pardon Form parameterized constructor called for target: "<< getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy)
{
	std::cout << "Pardon Form copy constructor called for target "<< copy.getTarget() << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
	if (this != &form)
	{
		AForm::operator=(form);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<< "Pardon Form destructor called."<< std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw std::runtime_error("Form is not signed.");
	if (executor.getGrade() > getExecuteGrade())
	{
		std::cout<< "Bureaucrat: "<< executor.getName()<< ", has grade: "<< executor.getGrade()<< ", Pardon Form exec grade: "<< getExecuteGrade()<<std::endl;
		throw std::runtime_error("Bureaucrat's grade is too low to execute the form.");
	}

	std::cout << "Target: "<< getTarget()<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
