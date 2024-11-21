/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-12 17:23:59 by epolkhov          #+#    #+#             */
/*   Updated: 2024-11-12 17:23:59 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool 				_isSigned;
		const int 			_signGrade;
		const int 			_executeGrade;
	public:
		Form();
		Form(std::string, int, int);
		Form(const Form& copy);
		Form& operator=(const Form&);
		~Form();

		std::string getName()const;
		bool getIsSigned()const;
		int getSignGrade()const;
		int getExecuteGrade()const;

		void beSigned(Bureaucrat& some);

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif