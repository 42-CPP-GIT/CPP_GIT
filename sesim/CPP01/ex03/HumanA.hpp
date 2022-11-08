/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:37:07 by sesim             #+#    #+#             */
/*   Updated: 2022/11/08 11:49:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name_;
		Weapon		&weapon_;
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void);
		~HumanA();
};

#endif
