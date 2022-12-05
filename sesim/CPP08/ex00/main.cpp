/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:45:56 by sesim             #+#    #+#             */
/*   Updated: 2022/12/05 12:02:17 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <deque>
#include "easyfind.hpp"

#define FIND_VAL 9

void	test(void)
{
	std::vector<int>	V;
	std::set<int>		S;
	std::list<int>		L;
	std::deque<int>		D;

	for (int i = 0; i < 10; ++i)
	{
		V.push_back(i);
		S.insert(i);
		L.push_back(i);
		D.push_back(i);
	}

	std::cout << "=== Contents of Vector ===\n";
	for (std::vector<int>::iterator it = V.begin(); it != V.end(); ++it)
		std::cout << " " << *it;
	std::cout << "\n\n";

	std::cout << "=== Contents of Set ===\n";
	for (std::set<int>::iterator it = S.begin(); it != S.end(); ++it)
		std::cout << " " << *it;
	std::cout << "\n\n";

	std::cout << "=== Contents of List ===\n";
	for (std::list<int>::iterator it = L.begin(); it != L.end(); ++it)
		std::cout << " " << *it;
	std::cout << "\n\n";
	
	std::cout << "=== Contents of Deque ===\n";
	for (std::deque<int>::iterator it = D.begin(); it != D.end(); ++it)
		std::cout << " " << *it;
	std::cout << "\n";

	try
	{
		std::cout << "\n=== Found Value is " << FIND_VAL << " ===\n";
		std::vector<int>::iterator	it_v(easyfind(V, FIND_VAL));
		std::set<int>::iterator		it_s(easyfind(S, FIND_VAL));
		std::list<int>::iterator	it_l(easyfind(L, FIND_VAL));
		std::deque<int>::iterator	it_d(easyfind(D, FIND_VAL));

		if (*it_v == FIND_VAL && *it_s == FIND_VAL && *it_l == FIND_VAL && *it_d == FIND_VAL)
			std::cout << "Value in the lists" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

int	main(void)
{
	test();
	return (0);
}