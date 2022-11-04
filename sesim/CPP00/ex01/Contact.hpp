/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:17:06 by sesim             #+#    #+#             */
/*   Updated: 2022/11/02 15:58:40 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nick_name_;
		std::string phone_number_;
		std::string darkest_secret_;
	public:
		Contact(void);
		void	AddBook(const std::string str[5]);
		void	printSimpleInfo(int n);
		void	printMoreInfo(int n);
		~Contact();
};

#endif
