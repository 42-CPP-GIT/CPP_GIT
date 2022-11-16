/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtil.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:45:02 by junoh             #+#    #+#             */
/*   Updated: 2022/11/11 15:09:38 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->cnt_ = 0;
    this->idx_ = -1;
}

void PhoneBook::setCnt(int cnt){
    this->cnt_ = cnt;
}

void PhoneBook::setIdx(int idx){
    this->idx_ = idx;
}

int PhoneBook::getIdx(void){
    return (this->idx_);
}

int PhoneBook::getCnt(void){
    return (this->cnt_);
}

PhoneBook::~PhoneBook()
{
    std::cout << "\n@@@@ PhoneBook Service is Over@@@@\n" << std::endl;
}