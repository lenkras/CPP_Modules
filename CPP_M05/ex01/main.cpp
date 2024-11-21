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

int main()
{
    try
    {
        Bureaucrat john("John", 1); // Grade 1, highest possible
        Bureaucrat jane("Jane", 150); // Grade 150, lowest possible

        Form form1("Form1", 50, 100); // Form requiring grade 50 to sign, grade 100 to execute
        Form form2("Form2", 30, 50); // Form requiring grade 30 to sign, grade 50 to execute

        std::cout << form1 << std::endl;
        john.signForm(form1); // John should sign this form
        std::cout << form1 << std::endl;
        jane.signForm(form1); // Jane shouldn't be able to sign this form

        std::cout << form2 << std::endl;
        john.signForm(form2); // John should sign this form
        std::cout << form2 << std::endl;
        jane.signForm(form2); // Jane shouldn't be able to sign this form

        // Test copy constructor for Bureaucrat
        Bureaucrat johnCopy(john); // Copy constructor should be called
        std::cout << "Copy of John: " << johnCopy << std::endl;

        // Test assignment operator for Bureaucrat
        Bureaucrat janeAssigned;
        janeAssigned = john; // Assignment operator should be called
        std::cout << "Assigned to Jane: " << janeAssigned << std::endl;

        // Test copy constructor for Form
        Form form1Copy(form1); // Copy constructor for Form should be called
        std::cout << "Copy of Form1: " << form1Copy << std::endl;
        

        // Test assignment operator for Form
        Form form2Assigned("Temporary", 40, 90); // First create an object
        std::cout << "Before assignment: " << form2Assigned << std::endl;

        form2Assigned = form2; // This invokes the assignment operator
        std::cout << "After assignment: " << form2Assigned << std::endl;

        // Modify and check if the copies are independent
        form2Assigned.beSigned(john); // John should sign the assigned form
        std::cout << "After John signs form2Assigned: " << form2Assigned << std::endl;
        std::cout << "Original Form2 (should not change): " << form2 << std::endl;


    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}