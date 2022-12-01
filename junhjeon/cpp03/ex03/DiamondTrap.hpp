/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:51:30 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/21 16:22:56 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private :
		std::string _name;
	public :
		DiamondTrap( std::string name );
		~DiamondTrap();
		DiamondTrap ( const DiamondTrap& copy );
		DiamondTrap& operator= ( const DiamondTrap& d );
		void	attack( const std::string& target );
		void	whoAmI( void );
};

#endif
