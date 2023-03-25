/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:02:07 by sesim             #+#    #+#             */
/*   Updated: 2022/11/20 14:57:59 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	const d(b);

	a = Fixed(1234.4321f);
	
	std::cout << "a is " << a << std::endl;
	std::cout << "a is " << b << std::endl;
	std::cout << "a is " << c << std::endl;
	std::cout << "a is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "a is " << b.toInt() << " as integer" << std::endl;
	std::cout << "a is " << c.toInt() << " as integer" << std::endl;
	std::cout << "a is " << d.toInt() << " as integer" << std::endl;
	return 0;
}