/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:16:22 by sesim             #+#    #+#             */
/*   Updated: 2022/11/02 11:38:13 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact()
{
}

void	Contact::AddBook(const std::string str[5])
{
	this->first_name_ = str[0];
	this->last_name_ = str[1];
	this->nick_name_ = str[2];
	this->phone_number_ = str[3];
	this->darkest_secret_ = str[4];
}

void	PrintInfo(void)
{
	std::cout << 
}
