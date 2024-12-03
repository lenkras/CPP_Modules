/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 15:39:47 by epolkhov          #+#    #+#             */
/*   Updated: 2024-11-22 15:39:47 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", "Robotomy default", 72, 45)
{
	std::cout<< "Robotomy Request Form default constructor called."<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("Robotomy Form", target, 72, 45)
{
	std::cout<< "Robtomy Form parameterized constructor called for target: "<< getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy)
{
	std::cout << "Robotomy Form copy constructor called for target "<< copy.getTarget() << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	if (this != &form)
	{
		AForm::operator=(form);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<< "Robotomy Form destructor called."<< std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw std::runtime_error("Form is not signed.");
	if (executor.getGrade() > getExecuteGrade())
	{
		std::cout<< "Bureaucrat: "<< executor.getName()<< ", has grade: "<< executor.getGrade()<< ", Robotomy Form exec grade: "<< getExecuteGrade()<< std::endl;
		throw std::runtime_error("Bureaucrat's grade is too low to execute the form.");
	}
	srand(time(0));
	std::cout<< "DRRRRIIIIILLLLLL noise."<< std::endl;
	if (rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy of " << getTarget() << " failed." << std::endl;
}
