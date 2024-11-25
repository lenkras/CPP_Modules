/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 16:42:29 by epolkhov          #+#    #+#             */
/*   Updated: 2024-11-21 16:42:29 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm","Shrubbery Default", 145, 137)
{
	std::cout << "Shrubbery default constructor called."<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout<< "Shrubbery parameterized constructor called for target: "<< getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy)
{
	std::cout << "Shrubbery copy constructor called for target "<< copy.getTarget()<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<< "Shrubbery destructor called."<< std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	if (this != &form)
	{
		AForm::operator=(form);
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw std::runtime_error("Form is not signed.");
	if (executor.getGrade() > getExecuteGrade())
	{
		std::cout<< "Bureaucrat: "<< executor.getName()<< ", has grade: "<< executor.getGrade()<< ", Shrubb Form exec grade: "<< getExecuteGrade()<< std::endl;
		throw std::runtime_error("Bureaucrat's grade is too low to execute the form.");
	}

	std::ofstream file(getTarget() + "_shrubbery");
	if (!file)
		throw std::runtime_error("File cannot be created.");
	file << "    *    \n   ***   \n  *****  \n ******* \n*********\n    |    \n";
	file.close();
	std::cout<< "Shrubbery Form is created and executed."<< std::endl;
}
