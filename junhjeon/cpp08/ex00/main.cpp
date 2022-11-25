/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:44:09 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/25 21:43:08 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <map>
#include <set>

int main()
{
	std::vector<int> v;
	std::list<int> l;
	for (int i = 1; i <= 5; i++)
	{
		v.push_back(i);
		l.push_back(i);
	}
	/*
	std::map<int, int> m1;
	std::map<int, int> m2;
	m1.insert(std::pair<int ,int>(1, 1));
	m2.insert(std::pair<int, int>(1, 1));
	*/

	try
	{
		std::cout << easyfind(v, 1) <<std::endl;
		std::cout << easyfind(l, 1) <<std::endl;
		//std::cout << easyfind(m1, 1) <<std::endl;
		//std::cout << easyfind(m2, 1) <<std::endl;
	}
	catch (int &a)
	{
		std::cout << "can't find" << std::endl;
	}
}
