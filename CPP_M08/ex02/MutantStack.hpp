/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-07 15:07:16 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-07 15:07:16 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T>

class MutantStack: public std::stack<T>
{
	public:
		using std::stack<T>::stack; // this line allows to use all the constructors of class stack
		using iterator = typename std::deque<T>::iterator;
		using const_iterator = typename std::deque<T>::const_iterator;

		iterator begin(){
			return this->c.begin();
		}

		iterator end(){
			return this->c.end();
		}

		const_iterator begin()const{
			return this->c.begin();
		}

		const_iterator end()const{
			return this->c.end();
		}
};