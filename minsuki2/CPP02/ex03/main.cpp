/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/01 16:42:06 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {

	Point const A( -3.69f, -6.66f );
	Point const B( 6.71f, -6.06f );
	Point const C( -1.14f, 5.37f );
	Point const P( 0.09f, -3.05f );

	std::cout << A.getXcordi() << std::endl;
	std::cout << A.getYcordi() << std::endl;
	std::cout << B.getXcordi() << std::endl;
	std::cout << B.getYcordi() << std::endl;
	std::cout << C.getXcordi() << std::endl;
	std::cout << C.getYcordi() << std::endl;
	std::cout << P.getYcordi() << std::endl;
	std::cout << P.getYcordi() << std::endl;

	bsp( A, B, C, P );
	return 0;
}
