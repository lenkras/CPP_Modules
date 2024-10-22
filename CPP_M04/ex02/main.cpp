/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 12:33:48 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-15 12:33:48 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----------CREATE AN ANIMAL ARRAY-----------"<< std::endl;
    const int size = 13;
    if (size <= 0 || size > 100)
    {
        std::cerr<< "Size of array should be in range of 1 - 100."<< std::endl;
        return (1);
    }
     Animal *animals[size];
    for (int i = 0; i < size / 2; i++)
    {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; i++)
    {
        animals[i] = new Cat();
    }
    for (int i= 0; i < size; i++)
    {
        animals[i]->makeSound();
    }
    std::cout<< "-------CLEAN UP EVERYTHING---------"<< std::endl;
	for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }
	return (0);
}