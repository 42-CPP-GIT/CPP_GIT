/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:33:28 by hchang            #+#    #+#             */
/*   Updated: 2022/12/01 14:02:18 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define FIND 9

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <exception>

class	OutofBoundException : public std::exception
{
	public :
		const char * what() const throw()
		{
			return ("ERROR : You Access Out of Bounds");
		}
};

template <typename T>
typename T::iterator	easyfind(T &_container, int N)
{
	typename T::iterator tmp;
	tmp = std::find(_container.begin(), _container.end(), N);

	if (_container.end() == tmp)
		throw OutofBoundException();
	return tmp;
}

#endif
