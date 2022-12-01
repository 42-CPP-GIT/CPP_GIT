/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:13:19 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 16:25:32 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Brain;

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
	virtual Brain*	getBrain(void) const;
};

#endif