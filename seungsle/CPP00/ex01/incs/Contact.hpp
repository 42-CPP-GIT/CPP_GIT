/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:41:30 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/29 16:34:36 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact
{
private:
	int	_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string _phoneNumber;
	std::string _darkestSecret;
	std::string	_nickName;
	
public:
	Contact();
	~Contact();
	void addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret, int index);
	void displayContact(void);
	void displayContactBySearch(int index);
	std::string printString10(std::string string);
};

#endif
