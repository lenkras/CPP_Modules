/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 09:00:24 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-25 09:00:24 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr<< "Error: invalid number of arguments."<< std::endl;
		return 1;
	}
	try{
		RPN str;
		str.parseString(argv[1]);
	}catch(const std::invalid_argument& e){
		std::cerr<< "Invalid argument: "<< e.what()<< std::endl;
	}
	catch(const std::exception& e){
		std::cerr<< "Unexpected error: "<<e.what()<< std::endl;
	}
}