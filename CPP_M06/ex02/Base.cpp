/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 11:46:02 by epolkhov          #+#    #+#             */
/*   Updated: 2025-01-07 11:46:02 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include "Base.hpp"

Base::~Base()
{
	std::cout<< "Base destructor called."<< std::endl;
}

Base* Base::generate()
{
	//std::srand(std::time(nullptr));
	int num = std::rand() % 31;
	if (num < 11)
	{
		std::cout<< "number A: "<< num<< std::endl;
		return new A();
	}
	else if (num < 21 && num > 10)
	{
		std::cout<< "number B: "<< num<< std::endl;
		return new B();
	}
	else{
		std::cout<< "number C: "<< num<< std::endl;
		return new C();
	}
}

void Base::identify(Base *p)
{
	if (dynamic_cast<A*>(p)){
		std::cout<< "A identified."<< std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout<< "B identified."<< std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout<< "C identified."<< std::endl;
	}
	else{
		std::cout << "Unknown type!" << std::endl;
	}
}

void Base::identify(Base& p) {
    // Using dynamic_cast with references is not directly possible. We will cast to pointers to identify the type.
    identify(&p);
}
