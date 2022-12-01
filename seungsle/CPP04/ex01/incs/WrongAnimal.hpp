/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:49:40 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 18:17:07 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
	std::string _sound;
	std::string _name;
public:
	WrongAnimal(/* args */);
	WrongAnimal(std::string type, std::string sound, std::string name);
	WrongAnimal(const WrongAnimal &WrongAnimal);
	~WrongAnimal();
	WrongAnimal& operator = (const WrongAnimal &source);

	void makeSound(void) const;
	void drinkWater(void) const;
	void eatTreat(void) const;

	void who(void) const;

	const std::string& getType(void) const;
	const std::string& getSound(void) const;
	const std::string& getName(void) const;
	void setType(std::string type);
	void setSound(std::string sound);
	void setName(std::string name);
};

#endif