/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:21:49 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/19 17:05:26 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

#include <iostream>

class Exception
{
private:
	std::string _errorMessage;
public:
	Exception();
	Exception(std::string errorMessage);
	~Exception();

	const std::string& getErrorMessage(void) const;
	void setErrorMessage(std::string errorMessage);

	std::string printException(void) const;
};

#endif