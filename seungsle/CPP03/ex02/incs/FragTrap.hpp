/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:16:12 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 11:12:55 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
private:

public:
	FragTrap(/* args */);
	FragTrap(std::string name);
	FragTrap(const FragTrap &FragTrap);
	~FragTrap();
	FragTrap& operator = (const FragTrap &source);

	// void printStatus(void);

	void highFivesGuys(void);
};

#endif