/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 02:56:24 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/25 12:15:20 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NotFound: public std::exception
{
public:
	const char *what() const throw()
	{
		return "not found";
	};
};

template<typename Iter, typename T>
Iter findIter( Iter it, Iter end, T search )
{
	Iter found = std::find(it, end, search);
	return (found);
}

template<typename T>
int easyfind( std::vector<T> & vec , T search)
{
	typename std::vector<T>::iterator findIt; // specify which iterator we'll use
	findIt = findIter(vec.begin(), vec.end(), search);
	if (findIt == vec.end())
		throw(NotFound());
	return (findIt - vec.begin());
}

#endif