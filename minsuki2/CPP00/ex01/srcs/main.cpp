/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:06:53 by minsuki2          #+#    #+#             */
/*   Updated: 2022/10/30 06:34:15 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"
// #include "PhoneBook.hpp"
//
std::string	myGetLine(const std::string &msg) {
	std::string	str;

	do {
		std::cout << msg;
		if (!std::getline(std::cin, str)) {
			std::cout << "\nEOF" << std::endl;
			std::exit(1);
		}
	} while (str.empty());
	return (str);
}

int	main(void) {
	PhoneBook	phone;

	while (true) {
		std::string order;

		order = myGetLine("Type Command(ADD, SEARCH, EXIT) : ");
		if (order == "ADD")
			phone.addBook();
			// std::cout << "add" << '\n';
		else if (order == "SEARCH")
			phone.searchBook();
			// std::cout << "search" << '\n';
		else if (order == "EXIT") {
			std::cout << "\n@@@@@ Good Bye! @@@@@" << '\n';
			return (SUCCESS);
		}
		else
			std::cout << "Wrong Command!!!(ADD, SEARCH, EXIT)" << '\n';
		// std::cout << order << std::endl;
	}
	return (SUCCESS);
}

// cin 다음에getline사용할 경우, ignore 넣어줘야 함
		/*
		std::cin >> order;
		std::cin.ignore();
		std::getline(std::cin, str);
		*/
