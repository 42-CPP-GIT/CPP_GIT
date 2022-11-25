/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:58:00 by hchang            #+#    #+#             */
/*   Updated: 2022/11/14 20:17:57 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{

	Fixed a(10);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );


	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << a + b << std::endl;
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;


	std::cout << a + 10 << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;

	// Fixed const a(10.3f);
	// Fixed const b(20.2f);

	// Fixed c(50.0f);
	// Fixed d(100.0f);

	// std::cout << Fixed::max(a, b) << std::endl;
	// std::cout << Fixed::min(a, b) << std::endl;

	// std::cout << Fixed::max(c, d) << std::endl;
	// std::cout << Fixed::min(c, d) << std::endl;


	// Fixed a(0);
	
	// std::cout << " a : " << a++ << std::endl; // 0
	// std::cout << " a : " << a << std::endl; // 0.00390625
	


	
	// return ((float)(this->getRawBits()) / (1 << this->_fixedBits));
	// 00000000 00000000 00000000 00000001 => int 1
	// 01000000 10000000 00000000 00000000 => float 1
	// 01000000 10000000 00000000 00000000 => float 1
	// float / 256 









	// Fixed a(10.3f);
	// Fixed b(20.2f);
	// Fixed c = a + b;
	// Fixed d = a - b;
	// Fixed e = a * b;
	// Fixed f = a / b;
	
	// std::cout << " < a : " << a << " > " << std::endl;
	// std::cout << " < b : " << b << " > " << std::endl;
	// std::cout << " < c : " << c << " > " << std::endl;
	// std::cout << " < d : " << d << " > " << std::endl;
	// std::cout << " < e : " << e << " > " << std::endl;
	// std::cout << " < f : " << f << " > " << std::endl;
	
	// std:: cout << "c == e : " << (c == e) << std::endl;
	// std:: cout << "c > e : " << (c > e) << std::endl;
	// std:: cout << "a == a : " << (a == a) << std::endl;
	// std:: cout << "a >= a : " << (a >= a) << std::endl;
	// std:: cout << "a != a : " << (a != a) << std::endl;
	// std:: cout << "a < b : " << (a < b) << std::endl;

	// std::cout << " < " << f << " > " << std::endl;
	// std::cout << " < " << g << " > " << std::endl;
	// 30 => 


	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	
	// std::cout << b << std::endl;
	
	// std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}
