/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:58:20 by sesim             #+#    #+#             */
/*   Updated: 2022/11/02 16:04:39 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string str;
	PhoneBook	book;

	do
	{
		if (!std::getline(std::cin, str))
		{
			std::cout << "err: EOF" << std::endl;
			std::exit(1);
		}
		else if (str == "ADD")
			book.Add();
		else if (str == "SEARCH")
			book.Search();
	}
	while (str != "EXIT");
}
