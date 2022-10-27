/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:14:07 by hchang            #+#    #+#             */
/*   Updated: 2022/10/27 11:55:01 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook		phonebook;
	std::string		str;

	std::cout << "ENTER COMMAND (ADD, SEARCH, EXIT) > ";
	while(std::getline(std::cin, str))
	{
		if (str == "EXIT")
			exit(1);
		else if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
		{
			std::cout << "--------------------------------------------" << std::endl;
			std::cout << "|              PHONE BOOK INFO             |" << std::endl;
			std::cout << "--------------------------------------------" << std::endl;
			std::cout << "|    INDEX|FIRST NAME| LAST NAME| NICK NAME|" << std::endl;
			std::cout << "--------------------------------------------" << std::endl;
			phonebook.print();
		}
		std::cout << "ENTER COMMAND (ADD, SEARCH, EXIT) > ";
	}
}
