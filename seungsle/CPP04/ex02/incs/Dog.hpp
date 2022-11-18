/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:51:10 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 23:46:10 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain *brain;
public:
	Dog(/* args */);
	Dog(std::string name);
	Dog(const Dog &dog);
	~Dog();
	Dog& operator = (const Dog &source);

	void makeSound(void) const;
	
	void playWithBall(void);
	void waggingTail(void);
};

#endif