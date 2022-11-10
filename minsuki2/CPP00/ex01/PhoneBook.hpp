/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:27:52 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/08 16:13:34 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

# define MSG_WELCOME	"\
,------. ,--.                               ,-----.                ,--.		\n\
|  .--. '|  ,---.  ,---. ,--,--,  ,---.    |  |) /_  ,---.  ,---. |  |,-.	\n\
|  '--' ||  .-.  || .-. ||     \\| .-. :    |  .-.  \\| .-. || .-. ||     /	\n\
|  | --' |  | |  |' '-' '|  ||  |\\  --.    |  '--' /' '-' '' '-' '|   \\ \\\n\
`--'     `--' `--' `---' `--''--' `----'    `------' `---'  `---' `--''--'	\n"

std::string		myGetLine(const std::string &msg);

class	PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addBook(void);
		void	searchBook(void);

	private:
		Contact _contact[8];
		int	_idx;
		int	_full_cnt;
};

#endif
