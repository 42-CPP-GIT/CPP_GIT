/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:14:17 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/02 20:54:34 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

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
	contact[currIndex].setFirstName(str[0]);
	contact[currIndex].setLastName(str[1]);
	contact[currIndex].setNickname(str[2]);
	contact[currIndex].setPhoneNumber(str[3]);
	contact[currIndex].setDarkestSecret(str[4]);
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
		std::cout << std::setw(10) << simpleStr(contact[i].getFirstName()).substr(0, 10) << "|";
		std::cout << std::setw(10) << simpleStr(contact[i].getLastName()).substr(0, 10) << "|";
		std::cout << std::setw(10) << simpleStr(contact[i].getNickname()).substr(0, 10) << "|" << std::endl;
	}
}

void	PhoneBook::searchInfo(std::string str)
{
	int i = 0;
	std::stringstream s(str);
	s >> i;
	if (s.fail())
		return ;
	{
		if (i + 1 > contactCount)
		{
			std::cout << "Contact not found" << std::endl;
			return ;
		}
		std::cout << "Index: " << i << std::endl;
		std::cout << "First name: " << contact[i].getFirstName() << std::endl;
		std::cout << "Last name: "  << contact[i].getLastName() << std::endl;
		std::cout << "Nickname: " << contact[i].getNickname() << std::endl;
		std::cout << "Phone number: " << contact[i].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contact[i].getDarkestSecret() << std::endl;
	}
}

int		PhoneBook::getCurrIndex(void) const
{
	return (this->currIndex);
}

int		PhoneBook::getContactCount(void) const
{
	return (this->contactCount);
}

bool	PhoneBook::empty(void) const
{
	return (this->contactCount == 0);
}

PhoneBook::PhoneBook() : currIndex(0), contactCount(0)
{
}
