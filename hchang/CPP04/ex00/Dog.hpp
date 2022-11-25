/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:51:15 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/10 19:37:06 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	std::string	_name;

public:
	Dog();
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog();
	void		makeSound(void) const;
	std::string	getName() const;
};

#endif
