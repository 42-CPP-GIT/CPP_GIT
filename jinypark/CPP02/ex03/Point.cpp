/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:30:51 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/05 12:38:57 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
private:
	Fixed x;
	Fixed y;
public:
	Point();
	Point(Fixed const a, Fixed const b);
	Point(const Fixed &obj);
	Point	&operator=(Point const &obj);
	~Point();
};

Point::Point(/* args */)
{
}

Point::~Point()
{
}

Point	&Point::operator=(Point const &obj)
{
	if (this != &obj)
	{
		this->x = obj.x;
		this->y = obj.y;
	}
	return (*this);
}
