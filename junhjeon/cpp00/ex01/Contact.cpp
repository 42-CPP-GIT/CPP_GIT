/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:37:16 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/03 17:46:50 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	Contact::set_firstname(std::string s)
{
	this -> firstname = s;
}

void	Contact::set_lastname(std::string s)
{
	this -> lastname = s;
}

void	Contact::set_nickname(std::string s)
{
	this -> nickname = s;
}

void	Contact::set_darkest_secret(std::string s)
{
	this -> darkest_secret = s;
}

void	Contact::set_phonenum(std::string s)
{
	this -> phonenum = s;
}

std::string	Contact::get_firstname(void)
{
	return (this -> firstname);
}

std::string Contact::get_lastname(void)
{
	return (this -> lastname);
}

std::string Contact::get_nickname(void)
{
	return (this -> nickname);
}

std::string Contact::get_darkest_secret(void)
{
	return (this -> darkest_secret);
}

std::string Contact::get_phonenum(void)
{
	return (this -> phonenum);
}

Contact::Contact()
{
	firstname = "";
	lastname = "";
	nickname = "";
	darkest_secret = "";
}

