/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:35:02 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/03 15:39:30 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{
	contact_num = 0;
	replace_num = 0;
}

int		is_num(std::string str)
{
	for (unsigned long i = 0; i < str.size(); i++)
		if(std::isdigit(str[i]))
			return (1);
	return (0);
}

void	fun_add(PhoneBook &phonebook)
{
	std::string	str;
	int			count;
	int			replace_num;
	Contact		*contact;

	count = phonebook.get_contact_num();
	if (count == 8)
	{
		replace_num = phonebook.get_replace_num();
		contact = phonebook.get_contact(replace_num);
		replace_num ++;
		if (replace_num == 8)
			replace_num = 0;
		phonebook.set_replace_num(replace_num);
	}
	else
		contact = phonebook.get_contact(count);

	str = "";
	while (str.size() == 0)
	{
		std::cout << "first name : ";
		std::getline(std::cin, str);
		contact->set_firstname(str);
		if (std::cin.eof())
			std::exit(0);
	}
	str = "";
	while (str.size() == 0)
	{
		std::cout << "last name : ";
		std::getline(std::cin, str);
		contact->set_lastname(str);
		if (std::cin.eof())
			std::exit(0);
	}
	str = "";
	while (str.size() == 0)
	{
		std::cout << "nick name : ";
		std::getline(std::cin, str);
		contact->set_nickname(str);
		if (std::cin.eof())
			std::exit(0);
	}
	str = "";
	while (str.size() == 0)
	{
		std::cout << "dark secret : ";
		std::getline(std::cin, str);
		contact->set_darkest_secret(str);
		if (std::cin.eof())
			std::exit(0);
	}
	str = "";
	while (str.size() == 0)
	{
		std::cout << "phone num : ";
		std::getline(std::cin, str);
		contact->set_phonenum(str);
		if (std::cin.eof())
			std::exit(0);
	}

	if (count != 8)
		phonebook.set_contact_num(count + 1);
	std::cout << "ADD END" << std::endl;
	return ;
}

void	fun_search(PhoneBook &phonebook)
{
	int			count;
	std::string	str;
	Contact		*contact;

	count = phonebook.get_contact_num();
	for (int i = 0; i < count; i ++)
	{
		contact = phonebook.get_contact(i);
		std::cout << std::setw(10) << i << "|";
		if (contact->get_firstname().size() > 10)
			std::cout << contact->get_firstname().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << contact->get_firstname() << "|";
		if (contact->get_lastname().size() > 10)
			std::cout << contact->get_lastname().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << contact->get_lastname() << "|";
		if (contact->get_nickname().size() > 10)
			std::cout << contact->get_nickname().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << contact->get_nickname() << "|";
		std::cout << std::endl;
	}
	std::cout << "write index to search : ";
	std::getline(std::cin, str);
	if (is_num(str) && '0' <= str[0] && str[0] <= '7' && str.size() == 1)
	{
		if ((str[0] - '0') >= phonebook.get_contact_num())
		{
			std::cout << "wrong index" << std::endl;
			return ;
		}
		int i;
		std::stringstream ssint(str);
		ssint >> i;
		contact = phonebook.get_contact(i);
		std::cout << contact->get_firstname() <<std::endl;
		std::cout << contact->get_lastname() <<std::endl;
		std::cout << contact->get_nickname() <<std::endl;
		std::cout << contact->get_darkest_secret() <<std::endl;
		std::cout << contact->get_phonenum() <<std::endl;
	}
	else
		std::cout << "wrong index" << std::endl;
}

void	PhoneBook::set_contact_num(int n)
{
	this -> contact_num = n;
}

int	PhoneBook::get_contact_num(void)
{
	return (this -> contact_num);
}


Contact*	PhoneBook::get_contact(int	n)
{
	return (&(this->contact)[n]);
}

void		PhoneBook::set_contact(int n, Contact &c)
{
	(this -> contact)[n] = c;
}

int			PhoneBook::get_replace_num(void)
{
	return (this -> replace_num);
}

void		PhoneBook::set_replace_num(int n)
{
	this -> replace_num = n;
}

int	main()
{
	PhoneBook phonebook;
	std::string str;

	while (1)
	{
		std::getline(std::cin, str);
		if (str == "ADD")
			fun_add(phonebook);
		if (str == "SEARCH") 
			fun_search(phonebook);
		if (str == "EXIT")
			break ;
		if (std::cin.eof())
			break ;
	}
	return (0);
}
