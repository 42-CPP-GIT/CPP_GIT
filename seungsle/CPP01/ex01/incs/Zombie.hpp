/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:28:38 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/26 14:00:12 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	~Zombie();
	void	setName(std::string name);
	Zombie*	zombieHorde( int N, std::string name );
	void	announce();
};


#endif