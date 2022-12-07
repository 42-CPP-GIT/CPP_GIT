/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:15:20 by sesim             #+#    #+#             */
/*   Updated: 2022/12/06 16:28:35 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(10.0f, 20.0f);
	Point	const b(0.0f, 4.0f);
	Point	c(4.0f, 0.0f);
	Point	point(1.999f, 1.999f);

	Point	const d(b);
	Point	const e = d;
	int	const a = 2;
	std::cout << d.getX() << " " << d.getY() << std::endl;
	std::cout << e.getX() << " " << e.getY() << std::endl;

	std::cout << (bsp(a, b, c, point) ? "Point in Triangle" : "Point is out of Triangle") << std::endl;
	return (0);
}