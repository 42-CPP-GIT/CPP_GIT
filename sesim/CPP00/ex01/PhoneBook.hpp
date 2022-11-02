/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:16:29 by sesim             #+#    #+#             */
/*   Updated: 2022/11/02 11:39:23 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONE_BOOK_H__
# define __PHONE_BOOK_H__

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		int		idx_;
		Contact	info_[8];
	public:
		PhoneBook();
		void	Add(void);
		void	Search(void);
		void	Exit(void);
		~PhoneBook();
};

#endif