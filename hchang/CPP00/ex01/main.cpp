/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:14:07 by hchang            #+#    #+#             */
/*   Updated: 2022/10/25 15:11:42 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	int 			idx(0);
	int				cnt(0);
	PhoneBook		pb[8];
	std::string		str;
	std::string		search_idx;

	std::cout << "ENTER COMMAND (ADD, SEARCH, EXIT) > ";
	while(std::getline(std::cin, str))
	{
		if (str == "EXIT")
			exit(1);
		else if (str == "ADD")
		{
			pb[idx].add();
			idx = (idx + 1) % 8;
			cnt++;
		}
		else if (str == "SEARCH")
		{
			std::cout << "--------------------------------------------" << std::endl;
			if (cnt > 8)
				cnt = 8;
			for (int i = 0; i < cnt ; i++)
				pb[i].print(i);
			std::cout << "--------------------------------------------" << std::endl;
			std::cout << "PICK YOUR INDEX (0 ~ 7) : ";
			std::getline(std::cin, search_idx);
			if (search_idx.size() != 1 || !std::isdigit(search_idx[0]) || std::stoi(search_idx) < 0 || std::stoi(search_idx) > 9)
				std::cout << "YOUR PUT WRONG INDEX!" << std::endl;
			else
			{
				if (std::stoi(search_idx) > cnt - 1)
					std::cout << "THERE IS NO CONTACT" << std::endl;
				else
					pb[std::stoi(search_idx)].print(std::stoi(search_idx));
			}
		}
		std::cout << "ENTER COMMAND (ADD, SEARCH, EXIT) > ";
	}
}