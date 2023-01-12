/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/20 15:41:15 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

# define MSG_FRAGTRAP_BORN	"which vault hunter would do the job best?"
# define MSG_FRAGTRAP		"FragTrap"
# define MSG_HIGHFIVESGUYS	"\"Gimme fives!\""

enum e_ft_max { FT_MAX_HP = 100, FT_MAX_EP = 100, FT_MAX_AD = 30 };

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& obj);
		FragTrap& operator=(const FragTrap& obj);
		~FragTrap(void);
		void		highFivesGuys(void) const;
	private:
		void		changeMaxValue_(void);
		void		inputMemberValue_(const FragTrap& obj);
};
#endif
