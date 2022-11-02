/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:55:14 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/02 14:00:14 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManager.hpp"

FileManager::FileManager(std::string fileName)
{
	setFileName(fileName);
}

FileManager::FileManager()
{
	
}

FileManager::~FileManager()
{
	
}

void	FileManager::readFile()
{
	std::ifstream t(getFileName());
	std::stringstream buffer;
	buffer << t.rdbuf();
	setContent(buffer.str());
}

void	FileManager::writeFile()
{
	std::ofstream file(getFileName());
	std::string my_string = getContent();
	file << my_string;
}

void	FileManager::setFileName(std::string fileName)
{
	this->_fileName = fileName;
}

void	FileManager::setContent(std::string content)
{
	this->_content = content;
}

std::string FileManager::getFileName()
{
	return (this->_fileName);
}

std::string FileManager::getContent()
{
	return (this->_content);
}
