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
	std::cout << "Testing correct Animal hierarchy:\n";
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Get Dog type: " << dog->getType() << " " << std::endl;
    std::cout << "Get Cat type: "<< cat->getType() << " " << std::endl;

    cat->makeSound(); 
    dog->makeSound(); 
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

	std::cout << "\nTesting WrongAnimal hierarchy:\n";
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Get WrongCat type: "<< wrongCat->getType() << " " << std::endl;

    wrongCat->makeSound(); 
    wrongMeta->makeSound();
    delete wrongMeta;
    delete wrongCat;

	return (0);
}