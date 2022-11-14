/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:02:07 by sesim             #+#    #+#             */
/*   Updated: 2022/11/10 12:06:28 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	const d(b);

	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout
	std::cout
	std::cout
	std::cout
	<< "a is " << a.toInt() << " as integer" << std::endl; << "b is " << b.toInt() << " as integer" << std::endl; << "c is " << c.toInt() << " as integer" << std::endl; << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}