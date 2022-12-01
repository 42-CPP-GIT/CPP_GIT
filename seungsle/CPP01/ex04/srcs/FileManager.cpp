/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:55:14 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/14 17:20:37 by seungsle         ###   ########.fr       */
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

const std::string FileManager::getFileName()
{
	return (this->_fileName);
}

const std::string FileManager::getContent()
{
	return (this->_content);
}
