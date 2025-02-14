/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-07 13:44:09 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-07 13:44:09 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element in a stack: "<< mstack.top() << std::endl;
	mstack.pop();
	std::cout <<"Stack size after pop(): "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(77);
	mstack.push(24);
	mstack.push(400);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout<< "it points to: " << *it<< std::endl;
	++it;
	std::cout<< "it points to: " << *it<< std::endl;
	--it;
	std::cout<< "it points to: " << *it<< std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;// it prints from bottom to top
		++it;
	}
	std::stack<int> s(mstack);
	std::stack<int> tempStack = s; 
	 while (!tempStack.empty())
    {
        std::cout << "Element: " << tempStack.top() << std::endl;// this prints from top to bottom
        tempStack.pop();
    }

	std::cout<< "---------- Test with List ------------"<< std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Top element in list: "<<lst.back() << std::endl; // Equivalent to mstack.top()
	std::cout <<"Stack size before pop_back(): "<< lst.size() << std::endl;
	lst.pop_back();
	std::cout <<"Stack size after pop_back(): "<< lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(77);
	lst.push_back(24);
	lst.push_back(400);
	lst.push_back(0);

	std::list<int>::iterator itl = lst.begin();
	std::list<int>::iterator itel = lst.end();

	while (itl != itel) {
		std::cout << *itl << std::endl;
		++itl;
	}
	std::list<int> sl(lst);
	return 0;
}