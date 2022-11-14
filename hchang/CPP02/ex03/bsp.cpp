/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:00:50 by hchang            #+#    #+#             */
/*   Updated: 2022/11/14 20:32:54 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	triangleArea(float const x1, float const y1, \
					float const x2, float const y2, \
					float const x3, float const y3)
{
	float equation = ((x1*y2) + (x2*y3) + (x3*y1) - (x2*y1) - (x3*y2) - (x1*y3)) / 2;
	Fixed res(equation > 0 ? equation : -equation);
	return res;
}


bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = triangleArea(a.getPointX().toFloat(), a.getPointY().toFloat(), \
				b.getPointX().toFloat(), b.getPointY().toFloat(), \
				c.getPointX().toFloat(), c.getPointY().toFloat());

	Fixed ABPointArea = triangleArea(a.getPointX().toFloat(), a.getPointY().toFloat(), \
				b.getPointX().toFloat(), b.getPointY().toFloat(), \
				point.getPointX().toFloat(), point.getPointY().toFloat());

	Fixed BCPointArea = triangleArea(b.getPointX().toFloat(), b.getPointY().toFloat(), \
			c.getPointX().toFloat(), c.getPointY().toFloat(), \
			point.getPointX().toFloat(), point.getPointY().toFloat());

	Fixed ACPointArea = triangleArea(a.getPointX().toFloat(), a.getPointY().toFloat(), \
			c.getPointX().toFloat(), c.getPointY().toFloat(), \
			point.getPointX().toFloat(), point.getPointY().toFloat());

	if (totalArea.toFloat() == 0.0 
		|| ABPointArea.toFloat() == 0.0 
		|| BCPointArea.toFloat() == 0.0 
		|| ACPointArea.toFloat() == 0.0)
		return (false);
	if (totalArea == (ABPointArea + BCPointArea + ACPointArea))
		return (true);
	return (false);


	// std::cout << "==============[Total Area]==============" << std::endl; 
	// std::cout << triangleArea(a.getPointX().toFloat(), a.getPointY().toFloat(), \
	// 			b.getPointX().toFloat(), b.getPointY().toFloat(), \
	// 			c.getPointX().toFloat(), c.getPointY().toFloat()) << std::endl;

	// std::cout << "==============[AB-Point Area]==============" << std::endl; 
	// std:: cout << triangleArea(a.getPointX().toFloat(), a.getPointY().toFloat(), \
	// 			b.getPointX().toFloat(), b.getPointY().toFloat(), \
	// 			point.getPointX().toFloat(), point.getPointY().toFloat()) << std::endl;

	// std::cout << "==============[BC-point Area]==============" << std::endl; 
	// std:: cout << triangleArea(b.getPointX().toFloat(), b.getPointY().toFloat(), \
	// 		c.getPointX().toFloat(), c.getPointY().toFloat(), \
	// 		point.getPointX().toFloat(), point.getPointY().toFloat()) << std::endl;

	// std::cout << "==============[AC-point Area]==============" << std::endl; 
	// std:: cout << triangleArea(a.getPointX().toFloat(), a.getPointY().toFloat(), \
	// 		c.getPointX().toFloat(), c.getPointY().toFloat(), \
	// 		point.getPointX().toFloat(), point.getPointY().toFloat()) << std::endl;



	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << c << std::endl;
	// std::cout << point << std::endl;
}
