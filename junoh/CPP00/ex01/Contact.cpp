/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:36:09 by junoh             #+#    #+#             */
/*   Updated: 2022/11/10 13:11:56 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string str){
    this->first_name_ = str;
}

void Contact::setLastName(std::string str){
    this->last_name_ = str;
}

void Contact::setNickName(std::string str){
    this->nick_name_ = str;
}

void Contact::setPhoneNumber(std::string str){
    this->phone_number_ = str;
}

void Contact::setDarkestSecret(std::string str){
    this->darkest_secret_ = str;
}

std::string Contact::getFirstName(void){
    return (this->first_name_);
}

std::string Contact::getLastName(void){
    return (this->last_name_);
}

std::string Contact::getNickName(void){
    return (this->nick_name_);
}

std::string Contact::getPhoneNumber(void){
    return (this->phone_number_);
}

std::string Contact::getDarkestSecret(void){
    return (this->darkest_secret_);
}

Contact::Contact()
{
}

Contact::~Contact()
{
}