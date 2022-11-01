/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:59:12 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/01 09:56:10 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

# include <iostream>
# include <sstream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

void		printPhoneBook(void);
std::string	ftGetline(std::string prompt, std::string &str);
bool		isdigitStr(std::string str);

class	PhoneBook
{
public:
	void	add(void);
	bool	addAsk(void);
	void	addInfo(std::string str[5]);
	bool	search(void);
	void	searchInfo(void);
	void	searchInfo(std::string str);
	int		getCurrIndex(void) const;
	int		getContactCount(void) const;
	bool	empty(void) const;
	PhoneBook();
private:
	Contact contact[8];
	int		currIndex;
	int		contactCount;
};

#endif
