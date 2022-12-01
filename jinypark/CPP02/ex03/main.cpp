/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:01:57 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/18 17:31:02 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(-2.8f, -1.3f);
	Point b(-5.3f, -7.4f);
	Point c(3.9f, -7.4f);
	Point p(1.7f, -6.7f);
	
	std::cout << (bsp(a, b, c, p) ? "True" : "False") << std::endl;
	return (0);
}