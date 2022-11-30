/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:13:19 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 18:44:49 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class Brain;

class AAnimal
{
protected:
	std::string type;
public:
	AAnimal(void);
	virtual	~AAnimal(void);
	AAnimal(const AAnimal &obj);
	AAnimal	&operator=(AAnimal const &obj);
	std::string	getType(void) const;
	virtual void	makeSound(void) const = 0;
	virtual Brain*	getBrain(void) const = 0;
};

#endif