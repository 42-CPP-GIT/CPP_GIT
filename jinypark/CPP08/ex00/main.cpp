/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:11:02 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/29 23:22:18 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;
	std::set<int> s;
	std::multiset<int> ms;
	std::map<int, int> ma;
	std::multimap<int, int> mma;

	std::cout << "-----vector test-----" << std::endl;
	v.push_back(3);
	v.push_back(4);
	std::cout << "Index: " << std::distance(v.begin(), easyfind(v, 3)) << std::endl;

	std::cout << "-----deque test-----" << std::endl;
	d.push_back(3);
	d.push_back(4);
	std::cout << "Index: " << std::distance(d.begin(), easyfind(d, 4)) << std::endl;

	std::cout << "-----list test-----" << std::endl;
	l.push_back(3);
	l.push_back(4);
	std::cout << "Index: " << std::distance(l.begin(), easyfind(l, 4)) << std::endl;

	std::cout << "-----set test-----" << std::endl;
	s.insert(9);
	s.insert(8);
	std::cout << "Index: " << std::distance(s.begin(), easyfind(s, 8)) << std::endl;

	std::cout << "-----multi set test-----" << std::endl;
	ms.insert(9);
	ms.insert(8);
	ms.insert(8);
	std::cout << "Index: " << std::distance(ms.begin(), easyfind(ms, 8)) << std::endl;

	std::cout << "-----map test-----" << std::endl;
	ma[1] = 99;
	ma[1] = 97;
	ma[2] = 3;
	ma[3] = 4;
	std::cout << "Index: " << std::distance(ma.begin(), easyfind(ma, 1)) << std::endl;
	std::cout << "Value " << easyfind(ma, 1)->second << std::endl;

	std::cout << "-----multi map test-----" << std::endl;
	mma.insert(std::pair<int, int>(1, 42));
	mma.insert(std::pair<int, int>(1, 43));
	mma.insert(std::pair<int, int>(2, 22));
	mma.insert(std::pair<int, int>(3, 33));
	std::cout << "Index: " << std::distance(mma.begin(), easyfind(mma, 1)) << std::endl;
	std::cout << "Value " << easyfind(mma, 1)->second << std::endl;
	return (0);
}