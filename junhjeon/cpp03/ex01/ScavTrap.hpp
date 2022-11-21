/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:09:12 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/21 16:10:26 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private :
		//std::string _name;
		//int	_hitPoints;
		//int	_energyPoints;
		//int	_attackDamage;
	public :
		ScavTrap( std::string name );
		~ScavTrap();
		ScavTrap( const ScavTrap& copy );
		ScavTrap& operator =(const ScavTrap & s );
		void	guardGate( void );
		void	attack( const std::string& target);
};

#endif
