/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:41:16 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 14:28:07 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main()
{
	try
	{
		//Bureaucrat a("1", 0);
		//Bureaucrat d("4", 151);
		Bureaucrat b("2", 150);
		//b.decre();
		b.incre();
		Bureaucrat c("3", 1);
		//c.incre();

		std::cout << b << c ;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
