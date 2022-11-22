/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:38:15 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/05 21:27:22 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	private :
		const Fixed& x;
		const Fixed& y;
		int field;
	public :
		Point(const Fixed &a,const Fixed &b);
		~Point();
		Point& operator =(const Point& p);
		Point(const Point& p);
		void setField( const Point& c );
		float	getX( void ) const;
		float	getY( void ) const;
};

#endif
