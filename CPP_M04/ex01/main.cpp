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
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    delete dog;
    delete cat;
    
    const int size = 4;
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
	for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }

	return (0);
}