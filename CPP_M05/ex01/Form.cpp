/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-12 17:24:12 by epolkhov          #+#    #+#             */
/*   Updated: 2024-11-12 17:24:12 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Unknown"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout<< "Form default constructor called."<< std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(execGrade)
{
	std::cout << "Form constructor called with parameters "<< name << ", "<< signGrade<< ", "<< execGrade<< std::endl;
	if (execGrade > 150)
		throw GradeTooLowException();
	else if (execGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& copy):_name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
	std::cout << "Form copy constructor called with name "<< _name<< std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called."<< std::endl;
}

Form& Form::operator=(const Form& form)
{
	std::cout << "Form assign operator caled."<< std::endl;
	if (this != &form)
	{
		_isSigned = form._isSigned;
	}
	return (*this);
}

std::string Form::getName()const
{
	return (_name);
}

bool Form::getIsSigned()const
{
	return (_isSigned);
}

int Form::getSignGrade()const
{
	return(_signGrade);
}

int Form::getExecuteGrade()const
{
	return (_executeGrade);
}

void Form::beSigned(Bureaucrat& some)
{
	if (some.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return("Grade is too high.");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low.");
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
	os<< "Form named: "<< form.getName() << ", which has sign status:  "<< form.getIsSigned()
		<< ", sign grade: "<< form.getSignGrade()<< ", and execute grade: " << form.getExecuteGrade()<< std::endl;
	return (os);
}
