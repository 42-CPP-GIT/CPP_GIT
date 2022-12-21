/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/07 19:32:39 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed a2;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(-3300.05f));
	Fixed const c1(Fixed(3300.05f));
	Fixed const c2(Fixed(33423.05f));
	Fixed const c3(Fixed(334234.05f));
	Fixed const d(Fixed(2234.234f));
	Fixed const e(Fixed(3234235));
	const Fixed f(Fixed(2234.234f));
	const Fixed i(Fixed(65536.234f));
	const Fixed i2(Fixed(-65536.234f));
	const Fixed h(Fixed(16384.234f));
	const Fixed h2(Fixed(-16384.234f));
	const Fixed g(Fixed(8192.234f));
	const Fixed g2(Fixed(-8192.234f));
	const Fixed j(Fixed(8388607.0f));
	const Fixed j2(Fixed(-8388607.0f));
	const Fixed k(Fixed(-8388608.0f));
	const Fixed l(Fixed(800000.0f));

	const Fixed two(Fixed(2));
	const Fixed two2(Fixed(-2));

	std::cout << "a         : " << a << std::endl;			// 0
	std::cout << "++a       : " << ++a << std::endl;			// 0.00390625
	std::cout << "a         : " << a << std::endl;			// 0.00390625
	std::cout << "a++       : " << a++ << std::endl;			// 0.00390625
	std::cout << "a         : " << a << std::endl;			// 0.0078125
	std::cout << "b         : " << b << std::endl;			// 10.1016
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
	std::cout << "c        : " << c << std::endl;
	std::cout << "c1        : " << c1 << std::endl;
	std::cout << "c2        : " << c2 << std::endl;
	std::cout << "c3        : " << c3 << std::endl;
	std::cout << "d         : " << d << std::endl;
	std::cout << "g         : " << g << std::endl;

	std::cout << "a + b     : " << a << " + " << b << " = " << a + b << std::endl;
	std::cout << "a - b     : " << a << " - " << b << " = " << a - b << std::endl;
	std::cout << "a * b     : " << a << " * " << b << " = " << a * b << std::endl;
	std::cout << "a / b     : " << a << " / " << b << " = " << a / b << std::endl;
	std::cout << "a * two     : " << a << " * " << two << " = " << a * two << std::endl;
	std::cout << "b * two     : " << b << " * " << two << " = " << b * two << std::endl;
	std::cout << "c * two     : " << c << " * " << two << " = " << c * two << std::endl;
	std::cout << "d * two     : " << d << " * " << two << " = " << d * two << std::endl;
	std::cout << "e * two     : " << e << " * " << two << " = " << e * two << std::endl;
	std::cout << "f * two     : " << f << " * " << two << " = " << f * two << std::endl;
	std::cout << "g * two     : " << g << " * " << two << " = " << g * two << std::endl;
	std::cout << "h * two     : " << h << " * " << two << " = " << h * two << std::endl;
	std::cout << "i * two     : " << i << " * " << two << " = " << i * two << std::endl;
	std::cout << "j * two     : " << j << " * " << two << " = " << j * two << std::endl;
	std::cout << "k * two     : " << k << " * " << two << " = " << k * two << std::endl;
	std::cout << "-g * two     : " << g2 << " * " << two << " = " << g2 * two << std::endl;
	std::cout << "-h * two     : " << h2 << " * " << two << " = " << h2 * two << std::endl;
	std::cout << "-i * two     : " << i2 << " * " << two << " = " << i2 * two << std::endl;
	std::cout << "-j * two     : " << j2 << " * " << two << " = " << j2 * two << std::endl;
	std::cout << "g * -two     : " << g << " * " << two2 << " = " << g * two2 << std::endl;
	std::cout << "h * -two     : " << h << " * " << two2 << " = " << h * two2 << std::endl;
	std::cout << "i * -two     : " << i << " * " << two2 << " = " << i * two2 << std::endl;
	std::cout << "j * -two     : " << j << " * " << two2 << " = " << j * two2 << std::endl;
	std::cout << "k * -two     : " << k << " * " << two2 << " = " << k * two2 << std::endl;
	std::cout << "-g * -two     : " << g2 << " * " << two2 << " = " << g2 * two2 << std::endl;
	std::cout << "-h * -two     : " << h2 << " * " << two2 << " = " << h2 * two2 << std::endl;
	std::cout << "-i * -two     : " << i2 << " * " << two2 << " = " << i2 * two2 << std::endl;
	std::cout << "-j * -two     : " << j2 << " * " << two2 << " = " << j2 * two2 << std::endl;
	std::cout << "a * 2.4     : " << a << " * " << 2.4f << " = " << a * 2.4f << std::endl;
	std::cout << "b * 6.1     : " << b << " * " << 6.1f << " = " << b * 6.1f << std::endl;
	std::cout << "c * 8.3     : " << c << " * " << 8.3f << " = " << c * 8.3f << std::endl;
	std::cout << "d * 9.3     : " << d << " * " << 9.3f << " = " << d * 9.3f << std::endl;
	std::cout << "e * 5.3     : " << e << " * " << 5.3f << " = " << e * 5.3f << std::endl;
	std::cout << "f * 4.2     : " << f << " * " << 4.2f << " = " << f * 4.2f << std::endl;
	std::cout << "g * 4.1     : " << g << " * " << 4.1f << " = " << g * 4.1f << std::endl;
	std::cout << "h * 9.1     : " << h << " * " << 9.1f << " = " << h * 9.1f << std::endl;
	std::cout << "i * 2.3     : " << i << " * " << 2.3f << " = " << i * 2.3f << std::endl;

	std::cout << "a / two     : " << a << " / " << two << " = " << a / two << std::endl;
	std::cout << "b / two     : " << b << " / " << two << " = " << b / two << std::endl;
	std::cout << "c / two     : " << c << " / " << two << " = " << c / two << std::endl;
	std::cout << "d / two     : " << d << " / " << two << " = " << d / two << std::endl;
	std::cout << "e / two     : " << e << " / " << two << " = " << e / two << std::endl;
	std::cout << "f / two     : " << f << " / " << two << " = " << f / two << std::endl;
	std::cout << "g / two     : " << g << " / " << two << " = " << g / two << std::endl;
	std::cout << "h / two     : " << h << " / " << two << " = " << h / two << std::endl;
	std::cout << "i / two     : " << i << " / " << two << " = " << i / two << std::endl;
	std::cout << "j / two     : " << j << " / " << two << " = " << j / two << std::endl;
	std::cout << "k / two     : " << k << " / " << two << " = " << k / two << std::endl;
	std::cout << "-g / two     : " << g2 << " / " << two << " = " << g2 / two << std::endl;
	std::cout << "-h / two     : " << h2 << " / " << two << " = " << h2 / two << std::endl;
	std::cout << "-i / two     : " << i2 << " / " << two << " = " << i2 / two << std::endl;
	std::cout << "-j / two     : " << j2 << " / " << two << " = " << j2 / two << std::endl;
	std::cout << "g / -two     : " << g << " / " << two2 << " = " << g / two2 << std::endl;
	std::cout << "h / -two     : " << h << " / " << two2 << " = " << h / two2 << std::endl;
	std::cout << "i / -two     : " << i << " / " << two2 << " = " << i / two2 << std::endl;
	std::cout << "j / -two     : " << j << " / " << two2 << " = " << j / two2 << std::endl;
	std::cout << "k / -two     : " << k << " / " << two2 << " = " << k / two2 << std::endl;
	std::cout << "-g / -two     : " << g2 << " / " << two2 << " = " << g2 / two2 << std::endl;
	std::cout << "-h / -two     : " << h2 << " / " << two2 << " = " << h2 / two2 << std::endl;
	std::cout << "-i / -two     : " << i2 << " / " << two2 << " = " << i2 / two2 << std::endl;
	std::cout << "-j / -two     : " << j2 << " / " << two2 << " = " << j2 / two2 << std::endl;
	std::cout << "a / 2.4     : " << a << " / " << 2.4f << " = " << a / 2.4f << std::endl;
	std::cout << "b / 6.1     : " << b << " / " << 6.1f << " = " << b / 6.1f << std::endl;
	std::cout << "c / 8.3     : " << c << " / " << 8.3f << " = " << c / 8.3f << std::endl;
	std::cout << "d / 9.3     : " << d << " / " << 9.3f << " = " << d / 9.3f << std::endl;
	std::cout << "e / 5.3     : " << e << " / " << 5.3f << " = " << e / 5.3f << std::endl;
	std::cout << "f / 4.2     : " << f << " / " << 4.2f << " = " << f / 4.2f << std::endl;
	std::cout << "g / 4.1     : " << g << " / " << 4.1f << " = " << g / 4.1f << std::endl;
	std::cout << "h / 9.1     : " << h << " / " << 9.1f << " = " << h / 9.1f << std::endl;
	std::cout << "i / 2.3     : " << i << " / " << 2.3f << " = " << i / 2.3f << std::endl;
	std::cout << "l * 0.39843 : " << l << " * " << 0.39843 << " = " << l * 0.39843f << std::endl;
	std::cout << "0.39843 * l : " << 0.39843 << " * " << l << " = " << Fixed(0.39843f) * l << std::endl;
	std::cout << "i / 0     : " << i << " / " << 0 << " = " << i / 0 << std::endl;
	return 0;
}
