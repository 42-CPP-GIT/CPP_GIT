/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:50:58 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/03 17:46:28 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string darkest_secret;
		std::string phonenum;
	public:
		Contact();
		void		set_firstname(std::string s);
		void		set_lastname(std::string s);
		void		set_nickname(std::string s);
		void		set_darkest_secret(std::string s);
		void		set_phonenum(std::string s);
		std::string	get_firstname(void);
		std::string	get_lastname(void);
		std::string	get_nickname(void);
		std::string	get_darkest_secret(void);
		std::string	get_phonenum(void);
};

#endif
