/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:49:56 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/26 12:00:07 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	void announce( void );
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );
};

#endif