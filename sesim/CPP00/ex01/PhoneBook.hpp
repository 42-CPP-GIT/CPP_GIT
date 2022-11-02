/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:16:29 by sesim             #+#    #+#             */
/*   Updated: 2022/11/02 15:59:09 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONE_BOOK_H__
# define __PHONE_BOOK_H__

#include "Contact.hpp"

class PhoneBook
{
	private:
		int		idx_;
		int		cnt_;
		Contact	info_[8];
	public:
		PhoneBook();
		void	Add(void);
		void	Search(void);
		~PhoneBook();
};

#endif
