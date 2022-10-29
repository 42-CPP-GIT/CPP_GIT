/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:06:21 by minsuki2          #+#    #+#             */
/*   Updated: 2022/10/30 06:44:43 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addBook(void) {
	std::string		input[INFO_N];

	std::cout << "< Contact List > " << std::endl;
	input[F_NAME] = myGetLine("ㄴ[First name]\t\t: ");
	input[L_NAME] = myGetLine("ㄴ[Last name]\t\t: ");
	input[N_NAME] = myGetLine("ㄴ[Nick name]\t\t: ");
	input[PH_NUM] = myGetLine("ㄴ[Phone number]\t: ");
	input[D_SECRET] = myGetLine("ㄴ[Darkest secret]\t: ");
	_contact[this->_idx++].inputValue(input);
}

void	PhoneBook::searchBook(void) {
	for (int i = 0; i < this->_idx; i++) {
		// this->_contact[i]
		// std::cout << "here" << i << '\n';
		_contact[i].display(i);
		// for (int j = 0; j < INFO_N; j++) {
	}
}

PhoneBook::PhoneBook() {
	this->_idx = 0;
}
