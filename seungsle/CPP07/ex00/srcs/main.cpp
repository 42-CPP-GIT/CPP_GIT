/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:33:51 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/23 00:42:50 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	// int a = 1;
	// int b = 2;
	double a = 10.4;
	double b = 4.29;
	std::cout << ">> SWAP" << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	swap(a, b);
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << ">> MIN" << std::endl;
	std::cout << min(a, b) << std::endl;
	std::cout << ">> MAX" << std::endl;
	std::cout << max(a, b) << std::endl;
}