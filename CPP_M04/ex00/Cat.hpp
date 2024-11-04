/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 14:02:07 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-15 14:02:07 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat& copy);
		~Cat();
		Cat& operator=(const Cat& copy);
		void makeSound()const override;
};

#endif