/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-02 10:33:31 by epolkhov          #+#    #+#             */
/*   Updated: 2024-09-02 10:33:31 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl start;

	start.complain("DEBUG");
	start.complain("INFO");
	start.complain("WARNING");
	start.complain("ERROR");
	start.complain("Come on");

	return (0);
}
