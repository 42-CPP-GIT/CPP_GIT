/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:09:12 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/15 19:23:51 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private :
		;
	public :
		ScavTrap( std::string name );
		~ScavTrap();
		ScavTrap( const ScavTrap& copy );
		ScavTrap& operator =(const ScavTrap & s );
		void	guardGate( void );
		void	attack( const std::string& target);
};

#endif
