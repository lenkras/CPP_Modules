/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcess.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-30 10:34:31 by epolkhov          #+#    #+#             */
/*   Updated: 2024-08-30 10:34:31 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcess.hpp"

FileProcess::FileProcess(const std::string &filename, const std::string &s1, const std::string &s2): 
_filename(filename), _s1(s1), _s2(s2)
{}

std::string FileProcess::readFile()
{
	std::ifstream file(_filename);
	if (!file.is_open())
	{
		std::cerr << "Error: failed to open the file." << std::endl;
		return ("");
	}
	std::string content;
	std::string line;
	while (std::getline(file, line))
	{
		content += line;
		if (!file.eof())
			content += "\n";
	}
	file.close();
	return (content);
}

std::string FileProcess::replaceString(const std::string &content, const std::string &s1, const std::string &s2)
{
	std::string newString = content;
	size_t i = 0;

	while ((i = newString.find(s1, i)) != std::string::npos)
	{
		newString.erase(i, s1.length());
		newString.insert(i, s2);
		i += s2.length();
	}
	return (newString);
}

void FileProcess::writeToFile(const std::string &content)
{
	std::ofstream outfile(_filename + ".replace");
	if (!outfile.is_open())
	{
		std::cerr << "Error: failed to open file for writing." << std::endl;
		return ;
	}
	outfile << content;
	outfile.close();
}

void FileProcess::processFile()
{
	std::string content = readFile();
	if (content.empty())
	{
		std::cerr << "File is empty or could not be read: check permission." << std::endl;
		return ;
	}
	std::string replaced = replaceString(content, _s1, _s2);
	writeToFile(replaced);
}
