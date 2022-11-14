/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:58:00 by hchang            #+#    #+#             */
/*   Updated: 2022/11/14 20:35:38 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point a(-0.0, -0.0);
	Point b(-4.0, -0.0);
	Point c(-0.0, -4.0);

	Point target(-1.99f, -2.0f);

	if (bsp(a, b, c, target))
		std::cout <<GRN "bsp result : [TRUE]" RESET<< std::endl;
	else
		std::cout <<RED "bsp result : [FALSE]" RESET<< std::endl;
	return 0;
}
