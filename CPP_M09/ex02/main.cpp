/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-04 10:39:27 by epolkhov          #+#    #+#             */
/*   Updated: 2025-03-04 10:39:27 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// bool check_input(const std::string &str)
// {
// 	std::vector<int> array;
// 	std::unordered_set<int> seen;

// 	for (size_t i = 0; i < str.length(); ++i)
// 	{
// 		if (!isdigit(str[i]) && str[i] != ' ')
// 		{
// 			std::cerr<< "Error"<< std::endl;
// 			return false;
// 		}
// 	}
// 	std::stringstream ss(str);
// 	int num;
// 	while (ss >> num)
// 	{
// 		if (num > std::numeric_limits<int>::max())
// 		{
// 			std::cerr<< "Error: number is too large"<< std::endl;
// 			return false;
// 		}
// 		array.push_back(num);
// 	}
// 	for (size_t i = 0; i < array.size(); ++i)
// 	{
// 		if (seen.find(array[i]) != seen.end())
// 		{
// 			std::cerr<< "Error: duplicates are not allowed."<< std::endl;
// 			return false;
// 		}
// 		else{
// 			seen.insert(array[i]);
// 		}
// 	}
// 	std::cout << "Before: ";
//     for (int n : array) {
//         std::cout << n << " ";
//     }
//     std::cout << std::endl;
// 	return true;
// }

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		std::cerr<< "Error: not enough arguments."<< std::endl;
		return 1;
	}
	std::string str;
	bool first_arg = true;
	int i = 1;
	while (i < argc)
	{
		if (!first_arg)
           	str.push_back(' ');
        first_arg = false;
		for(size_t j = 0; argv[i][j] != '\0'; ++j)
			str.push_back(argv[i][j]);
		i++;
	}
	PmergeMe set;
	try{
		if (set.check_input(str) == false)
			return 1;
		set.sortAndprint(set.getArray(), set.getDeque());
	}catch(const std::exception &e)
	{
		std::cerr<<e.what()<< std::endl;
	}
	

	return 0;
}