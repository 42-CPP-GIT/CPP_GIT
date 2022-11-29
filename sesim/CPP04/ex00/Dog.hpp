/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:21:06 by sesim             #+#    #+#             */
/*   Updated: 2022/11/28 15:39:31 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string	name_;

public:
	Dog();
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	void				makeSound(void) const;
	const std::string&	getName(void) const;
	~Dog();
};

#endif
