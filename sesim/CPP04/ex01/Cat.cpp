/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:23:59 by sesim             #+#    #+#             */
/*   Updated: 2022/12/08 16:55:32 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : name_("Cat"), brain_(new Brain)
{
	std::cout << "[ Cat Default Constructor Called ]" << std::endl;
}

Cat::Cat(const Cat& obj) : name_(obj.name_), brain_(new Brain(*obj.brain_))
{
	std::cout << "[ Cat Copy Constructor Called ]" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this == &obj)
		return (*this);
	this->name_ = obj.getName();
	if (this->brain_)
		delete this->brain_;
	this->brain_ = new Brain(*obj.brain_);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "[ " << this->getName() << " : Ya-ong ]" << std::endl;
}

void	Cat::getIdeas(void) const
{
	if (this->brain_)
		this->brain_->showIdeas();
}

const std::string&	Cat::getName(void) const
{
	return (this->name_);
}

Cat::~Cat()
{
	std::cout << "[ Cat Destructor Called ]" << std::endl;
	if (this->brain_)
		delete this->brain_;
}
