/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:51:04 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/02 14:06:53 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(FileManager &FileManager, std::string s1, std::string s2)
{
	this->_fileManager = &FileManager;
	this->_s1 = s1;
	this->_s2 = s2;
}

Replace::Replace()
{
	
}

Replace::~Replace()
{
	
}

void	Replace::replace(std::string &s, const std::string &search, const std::string &replace)
{
	for( size_t pos = 0; ; pos += replace.length() ) 
	{
		pos = s.find(search, pos);
		if(pos == std::string::npos) 
			break;
		s.erase(pos, search.length());
		s.insert(pos, replace);
	}
}

void	Replace::execute()
{
	if (this->_s1 == "")
	{
		std::cout << "Error: s1 cannot be empty string" << std::endl;
		return ;
	}
	this->_fileManager->readFile();
	setOriginalContent(this->_fileManager->getContent());
	std::string originalContent(getOriginalContent());
	replace(originalContent, this->_s1, this->_s2);
	setReplacedContent(originalContent);
	this->_fileManager->setFileName(this->_fileManager->getFileName() + ".replace");
	this->_fileManager->setContent(getReplacedContent());
	this->_fileManager->writeFile();
}

void	Replace::setOriginalContent(std::string originalContent)
{
	this->_originalContent = originalContent;
}

void	Replace::setReplacedContent(std::string replacedContent)
{
	this->_replacedContent = replacedContent;
}

std::string Replace::getOriginalContent()
{
	return (this->_originalContent);
}

std::string Replace::getReplacedContent()
{
	return (this->_replacedContent);
}
