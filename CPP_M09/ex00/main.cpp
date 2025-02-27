/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 09:09:42 by epolkhov          #+#    #+#             */
/*   Updated: 2025-02-25 09:09:42 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr<< "Invalid number of arguments."<<std::endl;
		return 1;
	}
	try{
		BitcoinExchange bitEx;
		bitEx.parseFile(argv[1], '|');
		bitEx.parseFile("data.csv", ',');
		bitEx.calcExchangeRate();
	}
	catch(const std::ios_base::failure& e){
		std::cerr<< "File error: "<< e.what()<<std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr<< "Invalid argument: "<< e.what()<< std::endl;
	}
	catch(const std::exception& e){
		std::cerr<< "Unexpected error: "<<e.what()<< std::endl;
	}
	catch(const std::runtime_error& e){
		std::cerr<< "Error: "<< e.what()<< std::endl;
	}
	return 0;
}