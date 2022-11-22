/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:49:04 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/15 19:23:32 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private :
		;
	public :
		FragTrap( std::string name );;
		~FragTrap();
		FragTrap( const FragTrap& copy );
		FragTrap& operator =(const FragTrap& f);
		void	highFivesGuys(void);
};

#endif
