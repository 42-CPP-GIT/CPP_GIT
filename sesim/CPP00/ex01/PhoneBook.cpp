/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:16:19 by sesim             #+#    #+#             */
/*   Updated: 2022/11/02 16:04:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->idx_ = 0;
	this->cnt_ = 0;
}

void	PhoneBook::Add(void)
{
	std::string	str[5];

	this->idx_ = ++this->idx_ % 8;
	if (++this->cnt_ > 7)
		this->cnt_ = 7;
	std::cout << "Put your first name : ";
	std::getline(std::cin, str[0]);
	std::cout << "Put your last name : ";
	std::getline(std::cin, str[1]);
	std::cout << "Put your nick name : ";
	std::getline(std::cin, str[2]);
	std::cout << "Put your phone number : ";
	std::getline(std::cin, str[3]);
	std::cout << "Put your darkest secret : ";
	std::getline(std::cin, str[4]);
	info_[idx_ - 1].AddBook(str);
}

void	PhoneBook::Search(void)
{
	for (int i = 0; i < this->cnt_; ++i)
		info_[i].printSimpleInfo(i);

}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook Exited" << std::endl;
}
