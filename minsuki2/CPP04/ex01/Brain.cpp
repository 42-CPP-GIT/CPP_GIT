/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:42:09 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/09 17:19:10 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << MSG_BRAIN << MSG_D_CONSTRUCT << std::endl;
	int i = 0;
	this->ideas_[i++] = "nice meet you";
	this->ideas_[i++] = "I'm fine thank you and you?";
	for (; i < Brain::n_ideas_; ++i) {
		this->ideas_[i] = "bye~";
	}
	return;
}

Brain::Brain(const Brain& obj) {
	std::cout << MSG_BRAIN << MSG_C_CONSTRUCT << std::endl;
	*this = obj;
	return;
}

Brain&	Brain::operator=(const Brain& obj) {
	std::cout << MSG_BRAIN << MSG_C_A_OPERATE << std::endl;
	for (int i = 0; i < Brain::n_ideas_; i++)
		this->ideas_[i] = obj.ideas_[i];
	return *this;
}

Brain::~Brain(void) {
	std::cout << MSG_BRAIN << MSG_DESTRCUT << std::endl;
	return ;
}

const std::string&	Brain::getIdea(int index) const {
	if (index < 0 && index >= Brain::n_ideas_) {
		std::cout << "Can't get idea " << index << ". Index out of range!"
			<< std::endl;
		return this->ideas_[Brain::n_ideas_ - 1];
	}
	return this->ideas_[index];
}

void	Brain::setIdea(int index, const std::string& idea) {
	if (index < 0 && index >= Brain::n_ideas_) {
		std::cout << "Can't set idea " << index << ". Index out of range!"
			<< std::endl;
		return ;
	}
	this->ideas_[index] = idea;
}
