/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:48:14 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/02 20:34:43 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

class Zombie
{
private:
	std::string _name;
public:
					Zombie(void);
					Zombie(std::string name);
    				~Zombie();
	void			setName(std::string name);
	void			announce(void);
	static Zombie*	zombieHorde(int N, std::string name);
};
