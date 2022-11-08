/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:06:53 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/08 19:05:53 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phone;
	std::string	order;

	std::cout << MSG_WELCOME << '\n';
	while (true) {
		order = myGetLine("Type Command(ADD, SEARCH, EXIT) : ");
		if (order == "ADD")
			phone.addBook();
		else if (order == "SEARCH")
			phone.searchBook();
		else if (order == "EXIT")
			break ;
		else
			std::cout << "Wrong Command!!!(ADD, SEARCH, EXIT)" << '\n';
	}
	return (SUCCESS);
}
