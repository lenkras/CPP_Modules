/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 14:15:40 by epolkhov          #+#    #+#             */
/*   Updated: 2024-11-08 14:15:40 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Unknown"), _grade(150){
	std::cout<< "Bureaucrat default constructor called."<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor with parameters called."<< std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called."<< std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	std::cout << "Bureaucrat assign operator called."<< std::endl;
	if (this != &copy)
	{
		_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called."<< std::endl;
}

const std::string &Bureaucrat::getName()const
{
	return (_name);
}

int Bureaucrat::getGrade()const
{
	return(_grade);
}

void Bureaucrat::incrementGrade()
{
	std::cout<< "Grade before increment: "<< _grade << std::endl;
	if (_grade == 1)
		throw GradeTooHighException();
	--_grade;
	std::cout<< "Grade after increment: "<< _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	std::cout<< "Grade before decrement: "<< _grade << std::endl;
	if (_grade == 150)
		throw GradeTooLowException();
	++_grade;
	std::cout<< "Grade after decrement: "<< _grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low.");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os<< bureaucrat.getName()<< ", bureaucrat grade "<< bureaucrat.getGrade()<< "."<< std::endl;
	return (os);
}

void Bureaucrat::signForm(Form& form)
{
	try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
