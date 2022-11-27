/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:13:19 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/27 16:34:07 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal(void);
	virtual	~Animal(void);
	Animal(const Animal &obj);
	Animal	&operator=(Animal const &obj);
	std::string	getType(void) const;
	virtual void	makeSound(void) const;
};

#endif