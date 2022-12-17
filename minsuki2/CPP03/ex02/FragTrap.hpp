/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/17 23:04:19 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

# define MSG_FRAGTRAP_BORN	""
# define MSG_FRAGTRAP		"FragTrap"
# define MSG_HIGHFIVESGUYS	"\"Shall we do positive high fives?\""

enum e_ft_max { FT_MAX_HP = 100, FT_MAX_EP = 50, FT_MAX_AD = 20 };

class FragTrap : public ClapTrap {
	public:
		FragTrap(void); FragTrap(const std::string& name); FragTrap(const FragTrap& obj);
		FragTrap& operator=(const FragTrap& obj);
		~FragTrap(void);
		void		highFivesGuys(void) const;
		void		checkStatus(void) const;
	private:
		void		changeMaxValue_(void);
};
#endif