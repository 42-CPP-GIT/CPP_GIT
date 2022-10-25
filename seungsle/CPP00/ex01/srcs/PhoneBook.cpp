/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:42:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/25 16:48:56 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

void	PhoneBook::add(void)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	Contact	newContact;

	std::cout << "[Add Contact]\n";
	std::cout << "Enter (First Name) : ";
	std::getline(std::cin, firstName);
	if (std::cin.eof())
		return ;
	std::cout << "Enter (Last Name) : ";
	std::getline(std::cin, lastName);
	if (std::cin.eof())
		return ;
	std::cout << "Enter (Nickname) : ";
	std::getline(std::cin, nickName);
	if (std::cin.eof())
		return ;
	std::cout << "Enter (PhoneNumber) : ";
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof())
		return ;
	std::cout << "Enter (Darkets Secret) : ";
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof())
		return ;
	newContact.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret, _size % 8);
	_contact[_size % 8] = newContact;
	_size++;
	return ;
}

bool	PhoneBook::isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
	if (*it == '-')
	{
		++it;
		return (std::isdigit(*it));
	}
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void	PhoneBook::search(void)
{
	std::string index;
	int			indexInt;

	std::cout << "   index  |first name| last name| nick name" << std::endl;
	for (int i = 0; i < _size; i++)
	{
		if (i >= 8)
			break ;
		_contact[i].displayContact();
	}
	std::cout << "[SEARCH CONTACT]\n" << std::endl;
	while (1)
	{
		std::cout << "Enter index you want to search (if you want to exit enter `-1`) : ";
		std::getline(std::cin, index);
		if (std::cin.eof())
			break ;
		if (isNumber(index))
		{
			indexInt = std::stoi(index);
		}
		else
		{
			std::cout << "invalid value" << std::endl;
			continue ;
		}
		if (indexInt == -1)
		{
			std::cout << "[EXIT SEARCH]" << std::endl;
			break ;
		}
		if (0 <= indexInt && indexInt < MAX_CAPACITY)
		{
			_contact[indexInt].displayContactBySearch(indexInt);
		}
		else
		{
			std::cout << "invalid value(out of bound)" << std::endl;
		}
	}
}

PhoneBook::PhoneBook()
{
	_size = 0;
}

PhoneBook::~PhoneBook()
{
	
}