/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 11:45:33 by epolkhov          #+#    #+#             */
/*   Updated: 2025-01-07 11:45:33 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	std::srand(std::time(nullptr));
	for (int i = 0; i < 6; i++)
	{
		Base *ptr = Base::generate();
		Base::identify(ptr);
		Base::identify(*ptr);
		delete ptr;
		std::cout << "--------------------"<< std::endl;
	}
	
	return(0);
}