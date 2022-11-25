/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:45:32 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/25 20:45:19 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <algorithm>

int	ft_error( void )
{
	return (-1);
}

template <typename T>
int	easyfind ( T a, int find_i )
{
	typename T::iterator iter;
	iter = std::find(a.begin(), a.end(), find_i);
	if (iter == a.end())
	{
		throw ft_error();
	}
	else
		return ((int)*iter);
}

/*//template <>
int	easyfind ( std::stack<int> a, int find_i )
{
	while (!a.empty())
	{
		if (a.top() == find_i)
			return (find_i);
		a.pop();
	}
	throw ft_error();
}
*/
/*
template <>
int	easyfind( std::map<const int, int> a, int find_i)
{
	std::map<int, int>::iterator iter;
	iter = std::find(a.begin(), a.end(), find_i);
	if (iter == a.end())
		throw ft_error();
	//int ret = iter -> first;
	std::cout << iter -> first << std::endl;
	return (1);
}

template <>
int	easyfind( std::set<int, int> a, int find_i)
{
	std::set<int, int>::iterator iter;
	iter = std::find(a.begin(), a.end(), find_i);
	if (iter == a.end())
		throw ft_error();
	//int ret = iter -> first;
	std::cout << iter->first << std::endl;
	return 1;
}*/
