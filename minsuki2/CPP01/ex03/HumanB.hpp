/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:16:47 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/22 15:26:13 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# define MSG_HUMAN_B	"[HumanB] "

class HumanB {
	public:
		HumanB(const std::string& name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon& weapon);

	private:
		HumanB(void);
		std::string		name_;
		Weapon			*weapon_;
};

#endif
