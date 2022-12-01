/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:06:21 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/08 21:46:51 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

std::string	myGetLine(const std::string &msg) {
	std::string	str;

	do {
		std::cout << msg;
		if (!std::getline(std::cin, str)) {
			std::cout << "\nDO NOT EOF!!! Type Again!";
			std::cin.clear();			// 버퍼 안에 비워주기
			std::clearerr(stdin);		//error bit 재설정해준다.
			std::cout << std::endl;
		}
	} while (str.empty());
	return (str);
}

static bool	_isOnlyNumber(const std::string &str) {
	for (size_t len = str.length(); len; len--)
		if (!std::isdigit(str.at(len - 1)))
			return (false);
	return (true);
}

static bool is_contact_index(char ch) {
	return (std::isdigit(ch) && '0' <= ch && ch <= '7');
}

static void _displayColumns(void) {
	printOffset10("index");
	printOffset10("first name");
	printOffset10("last name");
	printOffset10("nickname");
	std::cout << '\n';
}

void	PhoneBook::addBook(void) {
	std::string		input[INFO_N];

	std::cout << "\n< Contact List > " << '\n';
	input[F_NAME] = myGetLine("ㄴ[First name]\t\t: ");
	input[L_NAME] = myGetLine("ㄴ[Last name]\t\t: ");
	input[N_NAME] = myGetLine("ㄴ[Nick name]\t\t: ");
	do
		input[PH_NUM] = myGetLine("ㄴ[Phone number](0 ~ 9)\t: ");
	while (!_isOnlyNumber(input[PH_NUM]));
	input[D_SECRET] = myGetLine("ㄴ[Darkest secret]\t: ");
	this->_full_cnt += this->_full_cnt < 7;
	_contact[++this->_idx %= 8].inputValue(input);
	_displayColumns();
	for (int i = 0; i <= this->_full_cnt ; i++)
		_contact[i].display(i);
}

void	PhoneBook::searchBook(void) {
	if (this->_idx < 0) {
		std::cout << "Empty Contact!!!" << '\n';
		return ;
	}
	_displayColumns();
	for (int i = 0; i <= this->_full_cnt ; i++)
		_contact[i].display(i);
	std::string	index;
	while (true) {
		index = myGetLine("Which index do you want?(0 ~ 7) or end(-1) : ");
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
			if (this->_full_cnt < idx)
				std::cout << "Index Out of Range!!! or end(-1)" << '\n';
			else
				_contact[idx].searchBook();
		}
	}
}

PhoneBook::PhoneBook() {
	this->_idx = -1;
	this->_full_cnt = -1;
}

PhoneBook::~PhoneBook() {
	std::cout << "\n@@@@@ Good Bye! @@@@@" << std::endl;
}
