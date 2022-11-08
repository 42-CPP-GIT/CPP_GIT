/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:58:00 by hchang            #+#    #+#             */
/*   Updated: 2022/11/08 17:46:01 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point a(-0.0, -0.0);
	Point b(-4.0, -0.0);
	Point c(-0.0, -4.0);

	Point target(-1.8999999999f, 2.0f);
	
	if (bsp(a, b, c, target))
		std::cout << "bsp result : [TRUE]" << std::endl;
	else
		std::cout << "bsp result : [FALSE]" << std::endl;
	return 0;
}
