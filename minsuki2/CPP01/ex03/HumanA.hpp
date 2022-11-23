/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:11:39 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/23 18:26:48 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# define MSG_HUMAN_A	"[HumanA] "

class HumanA {
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA(void);

		void	attack(void);

	private:
		HumanA(void);

		std::string name_;
		Weapon &weapon_;
};

#endif
