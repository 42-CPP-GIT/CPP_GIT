/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:57:15 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/19 18:21:26 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exception.hpp"

Exception::Exception(): _errorMessage("undefined error")
{
	std::cout << "[Exception Constructor called]" << std::endl;
}

Exception::Exception(std::string errorMessage): _errorMessage(errorMessage)
{
	std::cout << "[Exception Constructor called]" << std::endl;
}

Exception::~Exception()
{
	std::cout << "[Exception destructor called]" << std::endl;
}

std::string Exception::printException(void) const
{
	return (std::string("<<Exception Occurred : " + getErrorMessage() + ">>"));
}

const std::string& Exception::getErrorMessage(void) const
{
	return (this->_errorMessage);
}

void Exception::setErrorMessage(std::string errorMessage)
{
	this->_errorMessage = errorMessage;
}