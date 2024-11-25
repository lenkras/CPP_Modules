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
        Bureaucrat john("John", 1);
        Bureaucrat jane("Jane", 114); 

        Form form1("Form1", 50, 100);
        Form form2("Form2", 30, 50);
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        form1.beSigned(john);
        form2.beSigned(jane);
        std::cout << form1 << std::endl;
        john.signForm(form1);
        std::cout << form1 << std::endl;
        jane.signForm(form1); 

        std::cout << form2 << std::endl;
        john.signForm(form2); 
        std::cout << form2 << std::endl;
        jane.signForm(form2);

        Bureaucrat johnCopy(john);
        std::cout << "Copy of John: " << johnCopy << std::endl;

        Bureaucrat janeAssigned;
        janeAssigned = john; 
        std::cout << "Assigned to Jane: " << janeAssigned << std::endl;

       
        Form form1Copy(form1); 
        std::cout << "Copy of Form1: " << form1Copy << std::endl;
        
        Form form2Assigned("Temporary", 40, 90); 
        std::cout << "Before assignment: " << form2Assigned << std::endl;

        form2Assigned = form2;
        std::cout << "After assignment: " << form2Assigned << std::endl;

        form2Assigned.beSigned(john);
        std::cout << "After John signs form2Assigned: " << form2Assigned << std::endl;
        std::cout << "Original Form2 (should not change): " << form2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}