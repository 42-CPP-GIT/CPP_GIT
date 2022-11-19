/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:12 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/19 18:42:16 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Exception.hpp"

int main(void)
{
	try
	{
		Bureaucrat b;
		std::cout << b << std::endl;
		b.decrement();
		Bureaucrat c;
		std::cout << c << std::endl;
	}
	catch(Exception *e)
	{
		std::cout << e->printException() << '\n';
		delete e;
	}
	try
	{
		Bureaucrat b("seungsle", 151);
		std::cout << b << std::endl;
	}
	catch(Exception *e)
	{
		std::cout << e->printException() << '\n';
		delete e;
	}
	try
	{
		Bureaucrat b("seungsle", 150);
		for (int i = 0; i < 149; i++)
			b.increment();
		std::cout << b << std::endl;
		b.increment();
		std::cout << b << std::endl;
	}
	catch(Exception *e)
	{
		std::cout << e->printException() << '\n';
		delete e;
	}
	
}