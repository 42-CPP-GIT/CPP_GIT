/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:51:01 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/02 14:06:17 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include "FileManager.hpp"

class Replace
{
private:
	FileManager *_fileManager;
	std::string _s1;
	std::string _s2;
	std::string _originalContent;
	std::string _replacedContent;
public:
	Replace(FileManager &FileManager, std::string s1, std::string s2);
	Replace();
	~Replace();
	void	execute(void);
	void	replace(std::string &s, const std::string &search, const std::string &replace);
	void	setOriginalContent(std::string originalContent);
	void	setReplacedContent(std::string replacedContent);
	std::string	getOriginalContent(void);
	std::string getReplacedContent(void);
};

#endif