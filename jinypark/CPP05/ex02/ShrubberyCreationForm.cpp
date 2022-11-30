/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:51:33 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/30 09:43:19 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	this->setName("Shrubbery Creation Form");
	this->setSignGrade(145);
	this->setExecuteGrade(137);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target) : target_(target)
{
	this->setName("Shrubbery Creation Form");
	this->setSignGrade(145);
	this->setExecuteGrade(137);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{

}