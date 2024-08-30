/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcess.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-30 10:34:08 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-30 10:34:08 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEPROCESS_HPP
#define FILEPROCESS_HPP

#include <iostream>
#include <string>
#include <fstream>

class FileProcess
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;

		std::string readFile();
		std::string replaceString(const std::string &content, const std::string &s1, const std::string &s2);
		void writeToFile(const std::string &content);
	public:
		FileProcess(const std::string &filename, const std::string &s1, const std::string &s2);
		void processFile();
};

#endif