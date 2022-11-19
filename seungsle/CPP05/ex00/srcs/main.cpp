/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:11:12 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/19 21:43:53 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	// catch(Bureaucrat::MyException *e)
	// {
	// 	std::cout << e->printException() << '\n';
	// 	e->what();
	// 	delete e;
	// }
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("seungsle", 151);
		std::cout << b << std::endl;
	}
	// catch(Bureaucrat::MyException *e)
	// {
	// 	std::cout << e->printException() << '\n';
	// 	delete e;
	// }
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
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
	// catch(Bureaucrat::MyException *e)
	// {
	// 	std::cout << e->printException() << '\n';
	// 	delete e;
	// }
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
}