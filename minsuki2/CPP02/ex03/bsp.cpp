/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:27 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/01 17:10:58 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


// bool is_same_sign( Point)
//
// bool inequality_line( const Fixed& delta_x, const Fixed& delta_x, const Fixed& delta_) {
// }

bool bsp( Point const a, Point const b, Point const c, Point const point ) {

	// const Fixed[4][2] = {{ a.getXcordi() - b.getXcordi(), a.getYcordi() - b.getYcordi() },
	//                         b.getXcordi() - c.getXcordi(), b.getYcordi() - b.getYcordi() },
	//
	(void)point;
	(void)a;
	(void)b;
	(void)c;
	// std::cout << "ax : " << a.getXcordi() << std::endl;
    //
	// Fixed delta[4] = { 120.3f, 32.1f, 32.43f, 3221.f };
	//                          // a.getYcordi() - b.getYcordi(),
	//                          // b.getXcordi() - c.getXcordi(),
	//                          // b.getYcordi() - b.getYcordi() };
	//
    //
	// for ( int i = 0; i < 4; i++ ) {
	//     std::cout << delta[i] << std::endl;
	// }
	a.setDeltaTo(b);

	return (false);
}

