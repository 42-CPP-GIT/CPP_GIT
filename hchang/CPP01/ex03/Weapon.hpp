/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:41:06 by hchang            #+#    #+#             */
/*   Updated: 2022/11/05 15:57:57 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

# include <string>
# include <iostream>

class Weapon
{
private:
    std::string	_type;
public:
    Weapon(std::string type);
    ~Weapon();
	const	std::string& getType() const;
    void	setType(const std::string &type);
};

#endif
