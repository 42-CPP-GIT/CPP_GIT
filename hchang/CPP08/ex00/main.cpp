/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:33:35 by hchang            #+#    #+#             */
/*   Updated: 2022/12/01 14:01:38 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> tmp_v;
	std::list<int> tmp_l;
	std::deque<int> tmp_q;

	for (int i = 0; i < 10; i++)
	{
		tmp_v.push_back(i);
		tmp_l.push_back(i);
		tmp_q.push_back(i);
	}

	try
	{
		std::vector<int>::iterator hey = easyfind(tmp_v, FIND);
		std::cout << *hey << std::endl;
	}
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::list<int>::iterator hey = easyfind(tmp_l, FIND);
		std::cout << *hey << std::endl;
	}
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::deque<int>::iterator hey = easyfind(tmp_q, FIND);
		std::cout << *hey << std::endl;
	}
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
