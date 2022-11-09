/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:39:26 by hchang            #+#    #+#             */
/*   Updated: 2022/10/27 17:39:16 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::setFirstName(std::string str)
{
    this->_firstName = str;
}

void    Contact::setLastName(std::string str)
{
	this->_lastName = str;
}

void    Contact::setNickName(std::string str)
{
	this->_nickName = str;
}

void    Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
}

void    Contact::setDarketSecret(std::string str)
{
	this->_darkestSecret = str;
}

std::string	Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string	Contact::getNickName(void)
{
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarketSecret(void)
{
	return (this->_darkestSecret);
}
