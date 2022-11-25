/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:14 by hchang            #+#    #+#             */
/*   Updated: 2022/11/10 13:47:43 by hchang           ###   ########.fr       */
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
    void	announce(void);
    void	setZombieName(std::string name);
    Zombie();
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif
