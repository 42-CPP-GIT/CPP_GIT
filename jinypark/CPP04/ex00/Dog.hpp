/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:13:19 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/16 13:05:52 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
protected:
public:
	Dog(void);
	~Dog(void);
	Dog(const Dog &obj);
	Dog	&operator=(Dog const &obj);
	virtual void	makeSound(void) const;
};

#endif