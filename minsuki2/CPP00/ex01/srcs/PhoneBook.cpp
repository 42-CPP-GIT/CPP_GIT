/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:06:21 by minsuki2          #+#    #+#             */
/*   Updated: 2022/10/30 20:48:26 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

static bool	_isOnlyNumber(const std::string &str) {
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
		if (!std::isdigit(*it))
			return (false);
	return (true);
}


void	PhoneBook::addBook(void) {
	std::string		input[INFO_N];

	std::cout << "\n< Contact List > " << std::endl;
	input[F_NAME] = myGetLine("ㄴ[First name]\t\t: ");
	input[L_NAME] = myGetLine("ㄴ[Last name]\t\t: ");
	input[N_NAME] = myGetLine("ㄴ[Nick name]\t\t: ");
	do
		input[PH_NUM] = myGetLine("ㄴ[Phone number](0 ~ 9)\t: ");
	while (!_isOnlyNumber(input[PH_NUM]));
	input[D_SECRET] = myGetLine("ㄴ[Darkest secret]\t: ");
	this->_full_cnt += this->_full_cnt < 7;
	_contact[++this->_idx %= 8].inputValue(input);
	displayColumns();
	for (int i = 0; i <= this->_full_cnt ; i++)
		_contact[i].display(i);
}

static bool is_contact_index(char ch) {
	return (std::isdigit(ch) && '0' <= ch && ch <= '7');
}

void	PhoneBook::searchBook(void) {
	if (this->_idx < 0) {
		std::cout << "Empty Contact!!!" << '\n';
		return ;
	}
	std::string	index;
	do {
		index = myGetLine("Which index do you want?(0 ~ 7) : ");
		if (index == "-1") {
			do
				index = myGetLine("Really want?(Y / N) : ");
			while (index != "Y" && index != "N");
			if (index == "Y")
				break ;
		}
		else if (index.length() > 1 || !is_contact_index(index[0]))
			std::cout << "Wrong index!!!(0 ~ 7) or end(-1)" << '\n';
		else {
			std::stringstream	index_stream(index);
			if (index_stream.fail())
				return ;
			int idx;
			index_stream >> idx;
			if (this->_idx < idx)
				std::cout << "Index Out of Range!!! or end(-1)" << '\n';
			else
				_contact[idx].searchBook();
		}
	} while (1);
}

// void	PhoneBook::searchBook(void) {
//
//     if (this->_idx < 0)
//     {
//         std::cout << "Empty Contact!!!" << '\n';
//         return ;
//     }
//     std::string	index;
//     int idx = -1;
//
//     do {
//         index = myGetLine("Which index do you want?(0 ~ 7) : ");
//         if (index == "-1")
//             return ;
//         else if (index.length() > 1 || !std::isdigit(index[0]))
//             std::cout << "Wrong index!!!(0 ~ 7) or end(-1)" << '\n';
//         else
//             break ;
//         idx = -1;
//     } while (idx < 0);
//     std::stringstream	index_stream(index);
//     if (index_stream.fail())
//         return ;
//     index_stream >> idx;
//     if (this->_idx < idx)
//         return ;
//     _contact[idx].searchBook();
// }

PhoneBook::PhoneBook() {
	this->_idx = -1;
	this->_full_cnt = -1;
}