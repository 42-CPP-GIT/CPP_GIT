/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:28:32 by jinypark          #+#    #+#             */
/*   Updated: 2023/01/01 21:56:22 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <random>
#include <ctime>

int main(int ac, char** av)
{
	srand(time(0));

	if (ac == 2)
	{
		int n(std::atoi(av[1]));
		std::cout << "----------1-----------" << std::endl;
		try
		{
			Span sp = Span(n);

			for (int i = 0; i < n; ++i)
				sp.addNumber(rand() % 100);
			sp.print();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "----------2-----------" << std::endl;
		try
		{
			Span sp = Span(n);

			for (int i = 0; i < n + 2; ++i)
				sp.addNumber(rand() % 100);
			sp.print();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "----------3-----------" << std::endl;
		try
		{
			Span sp = Span(n);

			sp.print();
			std::cout << sp.longestSpan() << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}