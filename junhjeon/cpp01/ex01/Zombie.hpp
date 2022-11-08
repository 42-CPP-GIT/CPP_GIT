/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:18:24 by junhjeon          #+#    #+#             */
/*   Updated: 2022/10/31 17:48:28 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void	announce( void );
		Zombie	*newZombie( std::string name );
		void	randomChump( std::string name );
		void	setName( std::string name );
		static Zombie	*zombieHorde( int n, std::string name );
		~Zombie();
		Zombie();
};

#endif
