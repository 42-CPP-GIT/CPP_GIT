/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:05:00 by hchang            #+#    #+#             */
/*   Updated: 2022/10/25 15:07:28 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add(void)
{
	std::string	str;

	std::cout << " ● first name : ";	
	std::getline(std::cin, str);
	this->firstName = str;
	std::cout << " ● last name : ";
	std::getline(std::cin, str);
	this->lastName = str;
	std::cout << " ● nickname : ";
	std::getline(std::cin, str);
	this->nickName = str;
	std::cout << " ● phone number : ";
	std::getline(std::cin, str);
	this->phoneNumber = str;
	std::cout << " ● darkest secret : ";
	std::getline(std::cin, str);
	this->darkestSecret = str;
}

void	PhoneBook::print(int idx)
{
	std::string	str;

	std::cout << std::setw(10) << idx;
	std::cout << "|";
	if (this->firstName.size() > 10)
		std::cout << this->firstName.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << this->firstName;
	std::cout << "|";
	if (this->lastName.size() > 10)
		std::cout << this->lastName.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << this->lastName;
	std::cout << "|";
	if (this->nickName.size() > 10)
		std::cout << this->nickName.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << this->nickName;
	std::cout << "|" << std::endl;
}



void PhoneBook::exit(void)
{
	std::exit(0);
}
