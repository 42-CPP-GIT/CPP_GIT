/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 02:56:27 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/23 03:38:50 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	int i = 0;
	std::vector<int> c(10);
	std::vector<int>::iterator it;
	for (it = c.begin(); it != c.end(); it++)
	{
		*it = i;
		i++;
	}
	try
	{
		std::cout << easyfind(c, 9) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}