/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:05:00 by hchang            #+#    #+#             */
/*   Updated: 2022/10/31 18:45:33 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_addIdx = -1;
	this->_searchIdx = -1;
}

void	PhoneBook::add(void)
{
	std::string	str;
	
	this->_searchIdx++;
	if (this->_searchIdx > 7)
		this->_searchIdx = 7;
	this->_addIdx = (this->_addIdx + 1) % 8;
	std::cout << " ● first name : ";	
	std::getline(std::cin, str);
	this->_contact[this->_addIdx].setFirstName(str);
	std::cout << " ● last name : ";
	std::getline(std::cin, str);
	this->_contact[this->_addIdx].setLastName(str);
	std::cout << " ● nickname : ";
	std::getline(std::cin, str);
	this->_contact[this->_addIdx].setNickName(str);
	std::cout << " ● phone number : ";
	std::getline(std::cin, str);
	this->_contact[this->_addIdx].setPhoneNumber(str);
	std::cout << " ● darkest secret : ";
	std::getline(std::cin, str);
	this->_contact[this->_addIdx].setDarketSecret(str);
}

void	PhoneBook::print(void)
{
	std::string	str;

	for (int i = 0; i <= this->_searchIdx; i++)
	{
		std::cout << std::setw(10) << i;
		std::cout << "|";
		if (this->_contact[i].getFirstName().size() > 10)
			std::cout << this->_contact[i].getFirstName().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contact[i].getFirstName();
		std::cout << "|";
		if (this->_contact[i].getLastName().size() > 10)
			std::cout << this->_contact[i].getLastName().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contact[i].getLastName();
		std::cout << "|";
		if (this->_contact[i].getNickName().size() > 10)
			std::cout << this->_contact[i].getNickName().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contact[i].getNickName();
		std::cout << "|" << std::endl;
	}
	searchPrint();
}

void PhoneBook::searchPrint(void)
{
	std::string	inputStirng;
	int			searchIdx(0);

	while (1)
	{
		std::cout << "PICK YOUR INDEX (press 9 to end SEARCH) : ";
		std::getline(std::cin, inputStirng);
		if (std::cin.eof())
			return ;
		if (inputStirng.size() != 1 || !std::isdigit(inputStirng[0]))
		{
			std::cout << "YOUR PUT WRONG INDEX!" << std::endl;
			continue;
		}
		std::stringstream ssIdx(inputStirng);
		ssIdx >> searchIdx;
		if (searchIdx == 9)
			return ;
		else if(searchIdx < 0 || searchIdx > 7)
		{
			std::cout << "OUT OF INDEX" << std::endl;
			continue;
		}
		else
		{
			if (searchIdx > this->_searchIdx)
			{
				std::cout << "THERE IS NO CONTACT" << std::endl;
				continue;
			}
			else
			{
				std::cout << "--------------------------------------------" << std::endl;
				std::cout << " ● first Name : " << this->_contact[searchIdx].getFirstName() << std::endl;
				std::cout << " ● last name : " << this->_contact[searchIdx].getLastName() << std::endl;
				std::cout << " ● nickname : " << this->_contact[searchIdx].getNickName() << std::endl;
				std::cout << " ● phone number : " << this->_contact[searchIdx].getPhoneNumber() << std::endl;
				std::cout << " ● darkest secret : " << this->_contact[searchIdx].getDarketSecret() << std::endl;
				std::cout << "--------------------------------------------" << std::endl;
			}
		}
	}
	std::cout << "--------------------------------------------" << std::endl;
}

void PhoneBook::exit(void)
{
	std::exit(0);
}
