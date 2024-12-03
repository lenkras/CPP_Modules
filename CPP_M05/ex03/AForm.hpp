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

#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string 	_name;
		const std::string	_target;
		const int 			_signGrade;
		const int 			_executeGrade;
		bool 				_isSigned;
		
	public:
		AForm();
		AForm(std::string, std::string, int, int);
		AForm(const AForm& copy);
		AForm& operator=(const AForm&);
		virtual ~AForm();

		std::string getName()const;
		bool getIsSigned()const;
		int getSignGrade()const;
		int getExecuteGrade()const;
		std::string getTarget()const;

		void beSigned(Bureaucrat& some);
		virtual void execute(const Bureaucrat& executor)const = 0;

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

std::ostream& operator<<(std::ostream &os, const AForm &form);

#endif