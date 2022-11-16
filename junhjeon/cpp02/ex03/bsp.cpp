/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:02:53 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/05 22:02:05 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool is_inside(float *x, float *y, int a, int b, int c, int p)
{
	float inclination;
	float const_c;
	float a1;
	float b1;
	if (x[a] == x[b] && y[a] == y[b])
		return (false);
	if (x[a] == x[b])
	{
		a1 = x[c] - x[a];
		b1 = x[p] - x[a];
		if (a1 * b1 <= 0)
			return (false);
		return (true);
	}
	if (y[a] == y[b])
	{
		a1 = y[c] - y[a];
		b1 = y[p] - y[a];
		if (a1 * b1 <= 0)
			return (false);
		return (true);
	}
	inclination = (y[a] - y[b]) / (x[a] - x[b]);
	const_c = y[a] - inclination * x[a];
	if (y[p] == inclination * x[p] + const_c)
		return (false);
	a1 =  y[c] - (inclination * x[c] + const_c);
	b1 =  y[p] - (inclination * x[p] + const_c);
	if (a1 * b1 <= 0)
		return (false);
	return (true);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float x[4];
	float y[4];

	x[0] = a.getX();
	y[0] = a.getY();
	x[1] = b.getX();
	y[1] = b.getY();
	x[2] = c.getX();
	y[2] = c.getY();
	x[3] = point.getX();
	y[3] = point.getY();

	if (!is_inside(&x[0], &y[0], 0, 1, 2, 3))
		return (false);
	if (!is_inside(&x[0], &y[0], 0, 2, 1, 3))
		return (false);
	if (!is_inside(&x[0], &y[0], 1, 2, 0, 3))
		return (false);
	return (true);
}

int main ()
{
	Fixed a(0);
	Fixed b(2);
	Fixed c(1);
	Fixed xa(1);
	Fixed xb(0.99f);

	Point pa(a, a);
	Point pb(b, a);
	Point pc(a, b);
	Point x(xa, xb);

	std::cout << "triangle" << std::endl;
	std::cout << "(" << pa.getX() << "," << pa.getY() << ")" << std::endl;
	std::cout << "(" << pb.getX() << "," << pb.getY() << ")" << std::endl;
	std::cout << "(" << pc.getX() << "," << pc.getY() << ")" << std::endl;
	std::cout << "point : " ;
	std::cout << "(" << x.getX() << "," << x.getY() << ")" ;

	if (bsp(pa, pb, pc, x))
		std::cout << " is inside" << std::endl;
	else
		std::cout << " is not inside" << std::endl;
	return (0);
}
