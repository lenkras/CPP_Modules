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

#include "AForm.hpp"

AForm::AForm(): _name("Unknown"),_target("default"), _signGrade(150), _executeGrade(150),  _isSigned(false)
{
	std::cout<< "AForm default constructor called."<< std::endl;
}

AForm::AForm(std::string name, std::string target, int signGrade, int execGrade): _name(name), _target(target), _signGrade(signGrade), _executeGrade(execGrade), _isSigned(false)
{
	std::cout << "AForm constructor called with parameters: "<< name << ", "<< signGrade<< ", "<< execGrade<< std::endl;
	if (execGrade > 150)
		throw GradeTooLowException();
	else if (execGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& copy):_name(copy._name), _target(copy._target), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade), _isSigned(copy._isSigned)
{
	std::cout << "AForm copy constructor called with name "<< _name<< std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called."<< std::endl;
}

AForm& AForm::operator=(const AForm& form)
{
	std::cout << "AForm assign operator caled."<< std::endl;
	if (this != &form)
	{
		_isSigned = form._isSigned;
	}
	return (*this);
}

std::string AForm::getName()const
{
	return (_name);
}

bool AForm::getIsSigned()const
{
	return (_isSigned);
}

int AForm::getSignGrade()const
{
	return(_signGrade);
}

int AForm::getExecuteGrade()const
{
	return (_executeGrade);
}

void AForm::beSigned(Bureaucrat& some)
{
	if (some.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout<< "Bureaucrat "<< some.getName()<< " signed form "<< getName()<< std::endl;

}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return("Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low.");
}

std::ostream& operator<<(std::ostream &os, const AForm &form)
{
	os<< "Form named: "<< form.getName() << " with target: "<< form.getTarget()<< ", which has sign status:  "<< form.getIsSigned()
		<< ", sign grade: "<< form.getSignGrade()<< ", and execute grade: " << form.getExecuteGrade()<< std::endl;
	return (os);
}

std::string AForm::getTarget()const
{
	return _target;
}
