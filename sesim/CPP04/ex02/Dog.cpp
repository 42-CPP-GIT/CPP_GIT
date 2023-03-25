/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:23:59 by sesim             #+#    #+#             */
/*   Updated: 2022/12/08 17:11:26 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : name_("Dog"), brain_(new Brain)
{
	std::cout << "[ Dog Default Constructor Called ]" << std::endl;
}

Dog::Dog(const Dog& obj) : name_(obj.name_), brain_(new Brain(*obj.brain_))
{
	std::cout << "[ Dog Copy Constructor Called ]" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this == &obj)
		return (*this);
	this->name_ = obj.getName();
	if (this->brain_)
		delete this->brain_;
	this->brain_ = new Brain(*obj.brain_);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "[ " << this->getName() << " : Wal ]" << std::endl;
}

void	Dog::getIdeas(void) const
{
	if (this->brain_)
		this->brain_->showIdeas();
}
const std::string&	Dog::getName(void) const
{
	return (this->name_);
}

Dog::~Dog()
{
	std::cout << "[ Dog Destructor Called ]" << std::endl;
	if (this->brain_)
		delete this->brain_;
	this->brain_ = NULL;
}