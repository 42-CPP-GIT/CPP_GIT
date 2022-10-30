/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:26:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/10/30 20:43:54 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Contact.hpp"

void printOffset10(const std::string &str) {

	if (str.length() <= 10)
		std::cout << std::setw(10) << str << '|';
	else
		std::cout << std::setw(10) << str.substr(0, 9) + "." << '|';
}

void Contact::display(const int &i) {
	std::cout << std::setw(10) << i << '|';
	printOffset10(this->_first_name);
	printOffset10(this->_last_name);
	printOffset10(this->_nick_name);
	std::cout << std::endl;
}

void displayColumns(void) {
	printOffset10("index");
	printOffset10("first name");
	printOffset10("last name");
	printOffset10("nickname");
	std::cout << std::endl;
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
