/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:03:48 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/29 15:37:00 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string	command;
	PhoneBook phoneBook;

	std::cout << "This is PhoneBook Program" << std::endl;
	while (1)
	{
		std::cout << "Please enter Commad (ADD, SEARCH, EXIT)! : ";
		std::getline(std::cin, command);
		if (std::cin.eof() || command == "EXIT")
			break ;
		else if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else
			std::cout << "Wrong Command!!" << std::endl;
		if (std::cin.eof())
			break ;
	}
}
