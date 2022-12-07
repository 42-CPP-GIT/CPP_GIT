/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:36:14 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/07 20:25:46 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
class Point {
	public:
		Point(void);
		Point(const float X, const float Y);
		Point(const Fixed X, const Fixed Y);
		Point(const Point& obj);
		~Point(void);
		const Fixed&	 getX(void) const;
		const Fixed&	 getY(void) const;

	private:
		Point& operator=(const Point& obj);
		Fixed const x_;
		Fixed const y_;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
