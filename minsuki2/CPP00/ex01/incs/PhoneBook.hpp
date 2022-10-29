/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:27:52 by minsuki2          #+#    #+#             */
/*   Updated: 2022/10/30 06:42:04 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"


std::string	myGetLine(const std::string &msg);

class	PhoneBook {
	public:
		PhoneBook();
		void	addBook(void);
		void	searchBook(void);

	private:
		Contact _contact[8];
		int		_idx;
};

#endif
