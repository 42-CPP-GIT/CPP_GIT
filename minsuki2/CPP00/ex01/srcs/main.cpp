/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:06:53 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/02 21:17:55 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"
// #include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phone;
	std::string	order;

	std::cout << MSG_WELCOME << '\n';
	do {
		order = myGetLine("Type Command(ADD, SEARCH, EXIT) : ");
		if (order == "ADD")
			phone.addBook();
		else if (order == "SEARCH")
			phone.searchBook();
		else if (order != "EXIT")
			std::cout << "Wrong Command!!!(ADD, SEARCH, EXIT)" << '\n';
	} while (order != "EXIT");
	return (SUCCESS);
}

// cin 다음에getline사용할 경우, ignore 넣어줘야 함
		/*
		std::cin >> order;
		std::cin.ignore();
		std::getline(std::cin, str);
		*/
