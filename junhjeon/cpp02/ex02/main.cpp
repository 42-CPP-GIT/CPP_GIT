/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:10:15 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 20:46:50 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a(0);
	Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed c(10.5f);
	Fixed d(6.77f);


	std::cout << a << std::endl;

	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << c - d << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}
