/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:41:16 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 15:53:37 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("1", 1);
		Bureaucrat b("2", 150);
		Form	fa("first", 3, 3);
		Form	fc("second", 149, 149);

		std::cout << a << b;
		a.signForm(fa);
		a.signForm(fc);
		std::cout << fc << fa;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
