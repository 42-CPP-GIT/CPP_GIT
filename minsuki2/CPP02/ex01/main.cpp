/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/28 23:04:08 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed	a;
	Fixed	const b(10);
	Fixed	const c(42.42f);
	Fixed	d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << std::endl;
	std::cout << "b is " << std::endl;
	std::cout << "c is " << std::endl;
	std::cout << "d is " << std::endl;

	std::cout << "a is " << a.toIstd::endl;
	std::cout << "b is " << std::endl;
	std::cout << "c is " << std::endl;
	std::cout << "d is " << std::endl;
	return 0;
}
