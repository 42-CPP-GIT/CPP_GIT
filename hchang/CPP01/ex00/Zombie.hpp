/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:21:09 by hchang            #+#    #+#             */
/*   Updated: 2022/11/10 13:49:14 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string _name;
public:
    void		announce(void);
    Zombie(std::string name);
    ~Zombie();
};

Zombie		*newZombie(std::string name);
void		randomChump(std::string name);

#endif
