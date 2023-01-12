/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 16:02:00 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define MSG_DIAMONDTRAP_BORN	"This is so risky!"
# define MSG_DIAMONDTRAP		"DiamondTrap"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap& operator=(const DiamondTrap& obj);
		virtual					~DiamondTrap(void);
		const std::string&		getName() const;
		const unsigned int&		getAttackDamage() const;
		void					whoAmI(void);
	private:
		void					inputMemberValue_(const DiamondTrap& obj);
		void					changeMaxValue_(void);
		std::string				name_;
};

#endif
