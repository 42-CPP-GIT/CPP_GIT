/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:28:49 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/23 19:12:51 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(const std::string& name, const std::string& before, const std::string& afeter)
	: file_name_(name), before_(before), after_(afeter) {}

Sed::~Sed(void) {}

const std::string&	Sed::getFileName(void) const { return this->file_name_; }
const std::string&	Sed::getBefore(void) const { return this->before_; }
const std::string&	Sed::getAfter(void) const { return this->after_; }
const std::string&	Sed::getFileScripts(void) const { return this->file_scripts_; }
void				Sed::setFileScripts(std::string input) { this->file_scripts_ = input; }

void	Sed::replace(void) {
	std::size_t i;
	const int before_len(this->before_.length());
	while (true) {
		if ((i = this->file_scripts_.find(this->before_)) == std::string::npos)
			break ;
		this->file_scripts_.erase(i, before_len);
		this->file_scripts_.insert(i, this->after_); // empty 조건문으로 느려지는 것 방지
	}
}
