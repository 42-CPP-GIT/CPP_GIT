/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:19:54 by jinypark          #+#    #+#             */
/*   Updated: 2022/10/28 16:01:13 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	
	printPhoneBook();
	while (1)
	{
		std::string	str;
		
		ftGetline("phonebook$ ", str);
		if (str == "ADD")
		{
			if (phonebook.getContactCount() < 8 || phonebook.addAsk())
				phonebook.add();
		}
		else if (str == "SEARCH")
		{
			if (!phonebook.search())
				continue ;
		}
		else if (str == "EXIT")
		{
			std::cout << "BYE!" << std::endl;
			return (0);
		}
	}
	return (0);
}
