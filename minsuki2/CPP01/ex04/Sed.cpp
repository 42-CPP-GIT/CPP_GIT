/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:28:49 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/22 20:15:26 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(const std::string& name, const std::string& before, const std::string& afeter)
	: file_name_(name), before_(before), after_(afeter) {
#ifdef debug
	std::cout << "[Debug] " << MSG_CREATE << MSG_ENDL;
#endif
}

Sed::~Sed(void) {
#ifdef debug
	std::cout << "[Debug] " << MSG_DESTROY << MSG_ENDL;
#endif
}

const std::string&	Sed::getFileName(void) { return this->file_name_; }
const std::string&	Sed::getBefore(void) { return this->before_; }
const std::string&	Sed::getAfter(void) { return this->after_; }
const std::string&	Sed::getFileScripts(void) { return this->file_scripts_; }
void				Sed::setFileScripts(std::string input) { this->file_scripts_ = input; }

void	Sed::fileDisplay(void) {
	std::cout << MSG_ENDL << MSG_ENDL << MSG_LINE << MSG_ENDL;
	std::cout << "* Filename : " << '"' << this->file_name_ << '"' << MSG_ENDL;
	std::cout << MSG_LINE << MSG_ENDL;
	std::cout << this->file_scripts_ << MSG_ENDL;
	std::cout << MSG_LINE << MSG_ENDL;
	std::cout << std::endl;
}

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
