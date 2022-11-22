/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:57:51 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 22:45:10 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream> 

class ClapTrap
{
	private :
		std::string _name;
		int	_hitPoint;
		int	_attackDamage;
		int _energyPoints;
	public :
		ClapTrap( std::string name );
		~ClapTrap();
		ClapTrap ( const ClapTrap& copy );
		ClapTrap& operator = ( const ClapTrap& c );
		void	attack( const std::string& target);
		void	takeDamage( unsigned int amount);
		void	beRepaired( unsigned int amount);

		int		getHitpoint( void ) const;
		int		getEnergyPoints( void ) const;
		int		getAttackDamage  (void ) const;
		std::string		getName ( void ) const;

		void	setHitpoint( int a );
		void	setEnergyPoints( int a );
		void	setAttackDamage( int a );
		void	setName( std::string name );
};

#endif
