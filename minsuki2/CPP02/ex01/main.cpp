/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/30 23:24:12 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed	a;
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	d(b);
	Fixed	e(7.625f);
	Fixed	f(-7.625f);
	Fixed	const g(-42.42f);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "g is " << g << std::endl;

	std::cout << "a is " << a.toInt() << MSG_INTEGER << std::endl;
	std::cout << "b is " << b.toInt() << MSG_INTEGER << std::endl;
	std::cout << "c is " << c.toInt() << MSG_INTEGER << std::endl;
	std::cout << "d is " << d.toInt() << MSG_INTEGER << std::endl;
	std::cout << "e is " << e.toInt() << MSG_INTEGER << std::endl;
	std::cout << "f is " << f.toInt() << MSG_INTEGER << std::endl;
	std::cout << "g is " << g.toInt() << MSG_INTEGER << std::endl;

	return 0;
}
