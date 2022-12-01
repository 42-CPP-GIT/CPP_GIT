/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:51:15 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/18 18:48:24 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	std::string	_name;
	Brain		*_brain;

public:
	Dog(Brain *brain); // gotta delete

	Dog();
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog();
	void		makeSound(void) const;
	void		noBrain(void);
	std::string	getName() const;
};

#endif
