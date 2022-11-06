/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:41:32 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/25 16:06:33 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONE_BOOK_H
# define PHONE_BOOK_H

#include "./Contact.hpp"

#define MAX_CAPACITY 8

class PhoneBook
{
private:
	Contact _contact[MAX_CAPACITY];
	int	_size;
public:
	PhoneBook(/* args */);
	~PhoneBook();
	void add(void);
	void search(void);
	bool isNumber(const std::string& s);
};

#endif
