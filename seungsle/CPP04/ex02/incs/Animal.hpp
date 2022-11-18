/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:49:40 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/18 11:42:18 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;
	std::string _sound;
	std::string _name;
public:
	Animal(/* args */);
	Animal(std::string type, std::string sound, std::string name);
	Animal(const Animal &Animal);
	virtual ~Animal();
	Animal& operator = (const Animal &source);

	virtual void makeSound(void) const = 0;
	virtual void drinkWater(void) const;
	virtual void eatTreat(void) const;

	void who(void) const;

	const std::string& getType(void) const;
	const std::string& getSound(void) const;
	const std::string& getName(void) const;
	void setType(std::string type);
	void setSound(std::string sound);
	void setName(std::string name);
};

#endif