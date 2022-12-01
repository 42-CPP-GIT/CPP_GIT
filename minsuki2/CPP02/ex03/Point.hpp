/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:36:14 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/01 17:11:30 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	public:
		Point( void );
		Point( const float X, const float Y );
		Point( const Point& obj );
		Point& operator = ( const Point& obj );
		~Point( void );
		static void setDeltaTo( const Point& front, const Point& behind );
		const Fixed&	 getXcordi( void ) const;
		const Fixed&	 getYcordi( void ) const;

	private:
		Fixed	x_;
		Fixed	y_;
		Fixed	delta_x_;
		Fixed	delta_y_;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
