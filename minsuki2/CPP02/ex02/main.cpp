/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/02 21:35:19 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed a2;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c1(Fixed(3300.05f));
	Fixed const c2(Fixed(33423.05f));
	Fixed const c3(Fixed(334234.05f));
	Fixed const d(Fixed(2234.234f));
	Fixed const e(Fixed(3234235));
	const Fixed f(Fixed(2234.234f));
	const Fixed g(Fixed(65536.234f));
	const Fixed h(Fixed(16384.234f));
	const Fixed i(Fixed(8192.234f));
	const Fixed two(Fixed(2));

	std::cout << "a         : " << a << std::endl;			// 0
	std::cout << "++a       : " << ++a << std::endl;			// 0.00390625
	std::cout << "a         : " << a << std::endl;			// 0.00390625
	std::cout << "a++       : " << a++ << std::endl;			// 0.00390625
	std::cout << "a         : " << a << std::endl;			// 0.0078125
	std::cout << "b         : " << b << std::endl;			// 10.1016
	std::cout << "g         : " << g << std::endl;
	std::cout << "max(a,b)  : " << Fixed::max(a, b) << std::endl; //10.1016
	std::cout << "max(e,f)  : " << Fixed::max(e, f) << std::endl; //10.1016
	std::cout << "(a >  b)  : " << (a > b) << std::endl;
	std::cout << "(a <= b)  : " << (a <= b) << std::endl;
	std::cout << "(a <  b)  : " << (a < b) << std::endl;
	std::cout << "(a >= b)  : " << (a >= b) << std::endl;
	std::cout << "(a == b)  : " << (a == b) << std::endl;
	std::cout << "(b == a)  : " << (b == a) << std::endl;
	std::cout << "(a == a2) : " << (a == a2) << std::endl;
	std::cout << "(a != b)  : " << (a != b) << std::endl;
	std::cout << "(d == f)  : " << (d == f) << std::endl;
	std::cout << "(d != f)  : " << (d != f) << std::endl;
	std::cout << "(f == a)  : " << (f == a) << std::endl;
	std::cout << "c1        : " << c1 << std::endl;
	std::cout << "c2        : " << c2 << std::endl;
	std::cout << "c3        : " << c3 << std::endl;
	std::cout << "d         : " << d << std::endl;

	std::cout << "a + b     : " << a << " + " << b << " = " << a + b << std::endl;
	std::cout << "a - b     : " << a << " - " << b << " = " << a - b << std::endl;
	std::cout << "a * b     : " << a << " * " << b << " = " << a * b << std::endl;
	std::cout << "a / b     : " << a << " / " << b << " = " << a / b << std::endl;
	std::cout << "g * two     : " << g << " * " << two << " = " << g * two << std::endl;
	std::cout << "h * two     : " << h << " * " << two << " = " << h * two << std::endl;
	std::cout << "i * two     : " << i << " * " << two << " = " << i * two << std::endl;

	return 0;
}
