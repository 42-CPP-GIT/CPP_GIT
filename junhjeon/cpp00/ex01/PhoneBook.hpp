/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:40:55 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/02 20:52:02 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class	PhoneBook{
	private:
		int		contact_num;
		int		replace_num;
		Contact contact[8];
	public:
	PhoneBook();
	void		set_contact_num(int	n);
	int			get_contact_num();
	Contact*	get_contact(int n);
	void		set_contact(int n, Contact &c);
	int			get_replace_num();
	void		set_replace_num(int n);
};

void	fun_add(PhoneBook &phonebook);
void	fun_search(PhoneBook &phonebook);
#endif
