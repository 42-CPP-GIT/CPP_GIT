/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 17:33:00 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

# define MSG_SCAVTRAP_BORN	"Greetings, fellow CL4P-TP unit. I simply wish to gain entrance"
# define MSG_SCAVTRAP		"ScavTrap"
# define MSG_GATEMODE		"is now in Gate keeper mode."

enum e_st_max { ST_MAX_HP = 100, ST_MAX_EP = 50, ST_MAX_AD = 20 };

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& obj);
		ScavTrap& operator=(const ScavTrap& obj);
		~ScavTrap(void);
		void		attack(const std::string& target);
		void		guardGate(void) const;
	private:
		void		inputMemberValue_(const ScavTrap& obj);
		void		changeMaxValue_(void);
};
#endif
