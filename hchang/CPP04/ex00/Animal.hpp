/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:44:14 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/10 19:31:32 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# define RESET "\033[0m"
# define IT "\e[0;3m"
# define RED "\e[0;31m"
# define GRN "\e[0;33m"

#include <iostream>

class Animal
{
protected:
	std::string	_type;

public:
	Animal();
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);
	virtual ~Animal();
	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif
