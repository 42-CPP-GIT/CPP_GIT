/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:33:51 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/24 11:13:31 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	// int a = 1;
	// int b = 2;
	// double a = 10.4;
	// double b = 4.29;
	// std::cout << ">> SWAP" << std::endl;
	// std::cout << "a : " << a << std::endl;
	// std::cout << "b : " << b << std::endl;
	// swap(a, b);
	// std::cout << "a : " << a << std::endl;
	// std::cout << "b : " << b << std::endl;
	// std::cout << ">> MIN" << std::endl;
	// std::cout << min(a, b) << std::endl;
	// std::cout << ">> MAX" << std::endl;
	// std::cout << max(a, b) << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}