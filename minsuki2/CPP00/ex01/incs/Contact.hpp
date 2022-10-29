/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:37:00 by minsuki2          #+#    #+#             */
/*   Updated: 2022/10/30 06:38:15 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>


# define	SUCCESS		0
# define	INFO_N		5
enum infoData {
	F_NAME, L_NAME, N_NAME, PH_NUM, D_SECRET
};

class Contact {
	public:
		void display(const int &i);
		void inputValue(std::string input[INFO_N]);

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nick_name;
		std::string		_phone_number;
		std::string		_dark_secret;
};

#endif
