/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:16:19 by sesim             #+#    #+#             */
/*   Updated: 2022/11/04 15:17:25 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

static bool	_isNotDigitString(std::string str)
{
	if (str.empty())
		return (true);
	for (size_t i = 0; i < str.length(); ++i)
		if (!std::isdigit(str.at(i)))
			return (true);
	return (false);
}

static void	_getLineExceptEOF(const std::string &output, std::string &input)
{
	std::cout << output;
	while (!std::getline(std::cin, input))
	{
		std::cin.clear();
		std::clearerr(stdin);
		std::cout << "\nPut right input" << std::endl;
		std::cout << output;
	}
}

PhoneBook::PhoneBook()
{
	this->idx_ = 0;
	this->cnt_ = -1;
}

void	PhoneBook::Add(void)
{
	std::string	str[5];

	_getLineExceptEOF("Put your first name : ", str[0]);
	_getLineExceptEOF("Put your last name : ", str[1]);
	_getLineExceptEOF("Put your nick name : ", str[2]);
	do
		_getLineExceptEOF("Put your phone number : ", str[3]);
	while (_isNotDigitString(str[3]))
		;
	_getLineExceptEOF("Put your darkest secret : ", str[4]);
	info_[idx_].AddBook(str);
	this->idx_ = ++this->idx_ % 8;
	this->cnt_ += this->cnt_ < 7;
}

void	PhoneBook::Search(void)
{
	std::stringstream	parser;
	std::string			input_val;
	int					input_index;

	if (cnt_ == -1)
	{
		std::cout << "phonebook is empty" << std::endl;
		return ;
	}
	for (int i = -1; i < this->cnt_; ++i)
		info_[i + 1].printSimpleInfo(i + 1);
	while (1)
	{
		_getLineExceptEOF("Put index to see (0 - 7)\n", input_val);
		parser.str(input_val);
		if (_isNotDigitString(input_val))
		{
			std::cout << "wrong input" << std::endl;
			continue ;
		}
		parser >> input_index;
		if (this->cnt_ >= input_index)
		{
			info_[input_index].printMoreInfo(input_index);
			return ;
		}
		else
			std::cout << "wrong range" << std::endl;
		parser.clear();
	}	
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook Exited" << std::endl;
}
