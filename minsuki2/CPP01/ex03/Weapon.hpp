/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:05:51 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/22 19:47:08 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# define	MSG_ENDL	'\n'
# define MSG_ATTACK		" attacks with their "
# define MSG_CREATE		" is created"
# define MSG_DESTROY	" is destoryed"
# define MSG_WEAPON		"[Weapon] "
# define MSG_CHANGE		" is changed"

class Weapon {
	public:
		Weapon(const std::string& type);
		~Weapon(void);
		const std::string&	getType(void);
		void				setType(const std::string& input_type);

	private:
		Weapon(void);
		std::string	type_;
};

#endif
