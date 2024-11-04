/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 15:09:14 by epolkhov          #+#    #+#             */
/*   Updated: 2024-10-29 15:09:14 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character: public ICharacter
{
	protected:
		AMateria* materias[4];
		std::string _name;
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& copy);
		Character& operator=(const Character& copy);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
} ;

#endif