/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:55:59 by sesim             #+#    #+#             */
/*   Updated: 2022/11/08 10:03:49 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str_origin = "HI THIS IS BRAIN";
	std::string	*str_ptr(&str_origin);
	std::string &str_ref(str_origin);

	std::cout << "===== addrress =====" << std::endl;
	std::cout << &str_origin << std::endl;
	std::cout << str_ptr << std::endl;
	std::cout << &str_ref << std::endl;

	std::cout << "===== value =====" << std::endl;
	std::cout << str_origin << std::endl;
	std::cout << *str_ptr << std::endl;
	std::cout << str_ref << std::endl;
	return (0);
}