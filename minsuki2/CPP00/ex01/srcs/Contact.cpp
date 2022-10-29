/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:26:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/10/30 07:02:23 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Contact.hpp"


static void printOffset10(const std::string &str) {
	std::string	res = str.substr(0, 9);

	if (res.length() > 10) {
		res += ".";
	}
	std::cout << std::setw(10) << res << '|';
}

void Contact::display(const int &i) {
	std::cout << std::setw(10) << i << '|';

	printOffset10(this->_first_name);
	printOffset10(this->_last_name);
	printOffset10(this->_nick_name);
	printOffset10(this->_phone_number);
	printOffset10(this->_dark_secret);
	std::cout << std::endl;
}

void Contact::inputValue(std::string input[INFO_N]) {
	this->_first_name = input[F_NAME];
	this->_last_name = input[L_NAME];
	this->_nick_name = input[N_NAME];
	this->_phone_number = input[PH_NUM];
	this->_dark_secret = input[D_SECRET];
}

