/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:11:35 by sesim             #+#    #+#             */
/*   Updated: 2022/12/06 16:29:16 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x_;
		Fixed const	y_;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point& obj);
	Point&			operator=(const Point& obj);
	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;
	~Point();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
