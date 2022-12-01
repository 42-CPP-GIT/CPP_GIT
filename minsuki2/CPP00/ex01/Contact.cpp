/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:26:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/08 21:47:57 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void printOffset10(const std::string &str) {
	std::cout << std::setw(10);
	if (str.length() <= 10)
		std::cout << str;
	else
		std::cout << str.substr(0, 9) + ".";
	std::cout << '|';
}

void Contact::display(const int &i) {
	std::cout << std::setw(10) << i << '|';
	printOffset10(this->_first_name);
	printOffset10(this->_last_name);
	printOffset10(this->_nick_name);
	std::cout << '\n';
}

void Contact::inputValue(std::string input[INFO_N]) {
	this->_first_name = input[F_NAME];
	this->_last_name = input[L_NAME];
	this->_nick_name = input[N_NAME];
	this->_phone_number = input[PH_NUM];
	this->_dark_secret = input[D_SECRET];
}

static void printMsgValue(const std::string &msg, const std::string &value) {
	std::cout << msg << value << '\n';
}

void Contact::searchBook(void) {
	printMsgValue("ㄴ[First name]\t\t:", this->_first_name);
	printMsgValue("ㄴ[Last name]\t\t:", this->_last_name);
	printMsgValue("ㄴ[Nick name]\t\t:", this->_nick_name);
	printMsgValue("ㄴ[Phone number]\t:", this->_phone_number);
	printMsgValue("ㄴ[Darkest secret]\t:", this->_dark_secret);
}
