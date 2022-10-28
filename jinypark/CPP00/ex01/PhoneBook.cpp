/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:14:17 by jinypark          #+#    #+#             */
/*   Updated: 2022/10/28 19:45:25 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void printPhoneBook(void)
{
	std::cout<< "                .-~~~~~~~~~-._       _.-~~~~~~~~~-.\n"
			<< "            __.'              ~.   .~      ADD     `.__\n"
			<< "          .'//     COMMAND:     \\./        SEARCH    \\\\`.\n"
			<< "        .'//                     |         EXIT        \\\\`.\n"
			<< "      .'// .-~\"\"\"\"\"\"\"~~~~-._     |     _,-~~~~\"\"\"\"\"\"\"~-. \\\\`. \n"
			<< "    .'//.-\"                 `-.  |  .-'                 \"-.\\\\`.\n"
			<< "  .'//______.============-..   \\ | /   ..-============.______\\`.\n"
			<< ".'______________________________\\|/______________________________`.\n";
}

static std::string simpleStr(std::string str)
{
    if (str.length() > 10)
        str[9] = '.';
    return (str);
}

bool	isdigitStr(std::string str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

std::string	ftGetline(std::string prompt, std::string &str)
{
	std::cout << prompt;
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << "exit" << std::endl;
		exit(0);
	}
	while (str.empty())
	{
		std::cout << prompt;		
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "exit" << std::endl;
			exit(0);
		}
	}
	return (str);
}

void	PhoneBook::add(void)
{
	std::string	contactInfo[5];
			
	ftGetline("→ Please input first name: ", contactInfo[0]);
	ftGetline("→ Please input last name: ", contactInfo[1]);
	ftGetline("→ Please input nickname: ", contactInfo[2]);
	while (!isdigitStr(ftGetline("→ Please input phone number(number only): ", contactInfo[3])))
		;
	ftGetline("→ Please input darkest secret: ", contactInfo[4]);
	this->addInfo(contactInfo);
}

bool	PhoneBook::addAsk(void)
{
	std::string answer;
	
	ftGetline("→ Old contact will be deleted. continue? (Y / n): ", answer);
	if (answer == "Y")
		return (true);
	return (false);
}

void	PhoneBook::addInfo(std::string str[5])
{
	contact[currIndex].firstName = str[0];
	contact[currIndex].lastName = str[1];
	contact[currIndex].nickname = str[2];
	contact[currIndex].phoneNumber = str[3];
	contact[currIndex].darkestSecret = str[4];
	currIndex = ++currIndex % 8;
	if (contactCount < 8)
		++contactCount;
}

bool	PhoneBook::search(void)
{
	if (this->empty())
				std::cout << "→ Empty phonebook!" << std::endl;
	else
	{
		std::string	answer;
	
		this->searchInfo();
		ftGetline("→ Please input any index you are looking for(0 ~ 7): ", answer);
		if (!isdigitStr(answer))
			return (false);
		this->searchInfo(answer);
	}
	return (true);
}

void	PhoneBook::searchInfo(void)
{
	for (int i = 0; i < contactCount; ++i)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << simpleStr(contact[i].firstName).substr(0, 10) << "|";
		std::cout << std::setw(10) << simpleStr(contact[i].lastName).substr(0, 10) << "|";
		std::cout << std::setw(10) << simpleStr(contact[i].nickname).substr(0, 10) << "|" << std::endl;
	}
}

void	PhoneBook::searchInfo(std::string str)
{
	int i = 0;
	std::stringstream s(str);
	if (s.fail())
		return ;
	s >> i;
	{
		if (i + 1 > contactCount)
		{
			std::cout << "Contact not found" << std::endl;
			return ;
		}
		std::cout << "Index: " << i << std::endl;
		std::cout << "First name: " << contact[i].firstName << std::endl;
		std::cout << "Last name: "  << contact[i].lastName << std::endl;
		std::cout << "Nickname: " << contact[i].nickname << std::endl;
		std::cout << "Phone number: " << contact[i].phoneNumber << std::endl;
		std::cout << "Darkest secret: " << contact[i].darkestSecret << std::endl;
	}
}

int		PhoneBook::getCurrIndex(void)
{
	return (this->currIndex);
}

int		PhoneBook::getContactCount(void)
{
	return (this->contactCount);
}

bool	PhoneBook::empty(void)
{
	return (this->contactCount == 0);
}

PhoneBook::PhoneBook()
{
	this->currIndex = 0;
	this->contactCount = 0;
}
