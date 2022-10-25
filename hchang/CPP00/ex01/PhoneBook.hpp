/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:28:41 by hchang            #+#    #+#             */
/*   Updated: 2022/10/25 15:14:48 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONE_BOOK_HPP_
# define PHONE_BOOK_HPP_

# include <iomanip>
# include <string>
# include <iostream>
# include <sstream>


class PhoneBook
{
    private:
        std::string	firstName;
        std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

    public:
		void	print(int idx);
        void	add(void);
        void	search(void);
		void	exit(void);
};

# endif