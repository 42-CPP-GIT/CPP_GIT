/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/30 17:37:40 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed	a;
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << MSG_INTEGER << std::endl;
	std::cout << "b is " << b.toInt() << MSG_INTEGER << std::endl;
	std::cout << "c is " << c.toInt() << MSG_INTEGER << std::endl;
	std::cout << "d is " << d.toInt() << MSG_INTEGER << std::endl;

	float	e = \
				0b0100000011110100000000000000000000000000000000000000000000000000
	// std::cout << "a is " << a.toFloat() << MSG_FLOAT << std::endl;
	// std::cout << "b is " << b.toFloat() << MSG_FLOAT << std::endl;
	// std::cout << "c is " << c.toFloat() << MSG_FLOAT << std::endl;
	// std::cout << "d is " << d.toFloat() << MSG_FLOAT << std::endl;
	// std::cout << "e is " << e << MSG_FLOAT << std::endl;
	return 0;
}
