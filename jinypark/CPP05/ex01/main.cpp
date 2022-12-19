/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:59:42 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/19 15:48:20 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	a(25);
	Form		f("FORM", 25, 1);
	Form		f2("FORM", 1, 1);
	std::cout << f;
	a.signForm(&f);
	std::cout << "-----------------\n";
	std::cout << f;
	a.signForm(&f);

	a.signForm(&f2);
	return (0);
}