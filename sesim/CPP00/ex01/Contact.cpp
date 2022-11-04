/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:16:22 by sesim             #+#    #+#             */
/*   Updated: 2022/11/04 15:09:26 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static void	printRange(std::string str)
{
	if (str.length() < 11)
		std::cout << std::setw(10) << str << '|';
	else
		std::cout << std::setw(10) << str.substr(0, 9) + '.' << '|';
}

Contact::Contact(void)
{
}

void	Contact::AddBook(const std::string str[5])
{
	this->first_name_ = str[0];
	this->last_name_ = str[1];
	this->nick_name_ = str[2];
	this->phone_number_ = str[3];
	this->darkest_secret_ = str[4];
}

void	Contact::printSimpleInfo(int n)
{
	if (n == 0)
	{
		std::cout << '|';
		printRange("index");
		printRange("first name");
		printRange("last name");
		printRange("nickname");
		std::cout << std::endl;
	}
	std::cout << '|';
	std::cout << std::setw(10) << n << '|';
	printRange(this->first_name_);
	printRange(this->last_name_);
	printRange(this->nick_name_);
	std::cout << std::endl;
}

void	Contact::printMoreInfo(int n)
{
	std::cout << "=====" << n << "index info=====" << std::endl;
	std::cout << this->first_name_ << std::endl;
	std::cout << this->last_name_ << std::endl;
	std::cout << this->nick_name_ << std::endl;
	std::cout << this->phone_number_ << std::endl;
	std::cout << this->darkest_secret_ << std::endl;
}

Contact::~Contact()
{
}
