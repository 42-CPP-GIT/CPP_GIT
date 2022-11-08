/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:18:24 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/03 20:08:17 by junhjeon         ###   ########.fr       */
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
		~Zombie();
		Zombie();
		Zombie( std::string name);
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif
