/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 14:14:39 by epolkhov          #+#    #+#             */
/*   Updated: 2024-11-08 14:14:39 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someIntern;
        AForm* form;

        form = someIntern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        delete form;

        form = someIntern.makeForm("shrubbery creation", "Garden");
        std::cout << *form << std::endl;
        delete form;

        form = someIntern.makeForm("presidential pardon", "President");
        std::cout << *form << std::endl;
        delete form;

        form = someIntern.makeForm("invalid form", "Unknown");
        
        // Bureaucrat john("John", 14);
        // Bureaucrat lena("Lena", 45);
        // Bureaucrat dan("Dan", 1);

        // ShrubberyCreationForm shrub("John");
        // RobotomyRequestForm robot("Lena");
        // PresidentialPardonForm pardon("Dan");
        // std::cout<< "------ Bureaucrats -------"<< std::endl;
        // std::cout<< john<< std::endl;
        // std::cout<< lena<< std::endl;
        // std::cout<< dan<< std::endl;

        // std::cout<< "------ Forms -------"<< std::endl;
        // std::cout<< shrub;
        // std::cout<< robot;
        // std::cout<< pardon;

        // std::cout << "------ Forms be signed and exec-------"<< std::endl;
        // shrub.beSigned(john);
        // robot.beSigned(lena);
        // pardon.beSigned(dan);
        // shrub.execute(john);
        // robot.execute(lena);
        // pardon.execute(dan);

        // std::cout << "------ Bureaucrats sign and exec forms -------"<< std::endl;
        // john.signForm(shrub);
        // lena.signForm(robot);
        // dan.signForm(pardon);
        // john.executeForm(shrub);
        // lena.executeForm(robot);
        // dan.executeForm(pardon);

        // std::cout<< shrub;
        // std::cout<< robot;
        // std::cout<< pardon;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}