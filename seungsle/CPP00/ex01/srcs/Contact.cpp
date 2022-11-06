/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:42:07 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/29 15:37:56 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret, int index)
{
	this->_index = index;
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

void Contact::displayContact()
{

	std::cout << std::setw(10) << _index;
	std::cout << "|" << std::setw(10) << printString10(_firstName);
	std::cout << "|" << std::setw(10) << printString10(_lastName);
	std::cout << "|" << std::setw(10) << printString10(_nickName) << std::endl;
}

std::string Contact::printString10(std::string string)
{
	if (string.length() > 10)
	{
		return (string.substr(0, 9) + ".");
	}
	return (string);
}

void Contact::displayContactBySearch(int index)
{
	if (_index == index)
	{
		std::cout << "first name : " << _firstName << std::endl;
		std::cout << "last name : " << _lastName << std::endl;
		std::cout << "nick name : " << _nickName << std::endl;
		std::cout << "phone number : " << _phoneNumber << std::endl;
		std::cout << "darkets secret : " << _darkestSecret << std::endl;
	}
	else
	{
		std::cout << "no data!" << std::endl;
	}
	return ;
}

Contact::Contact()
{
	_index = -1;
}

Contact::~Contact()
{
	
}
