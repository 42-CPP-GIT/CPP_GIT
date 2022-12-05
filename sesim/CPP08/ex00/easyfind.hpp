/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:22:27 by sesim             #+#    #+#             */
/*   Updated: 2022/12/05 11:15:40 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <algorithm>

class OutOfBoundsException : public std::exception
{
	public:
		const char*	what() const throw();
};

template <typename T>
typename T::iterator	easyfind(T& arr, int to_find)
{
	typename T::iterator	pos;

	pos = std::find(arr.begin(), arr.end(), to_find);
	if (pos == arr.end())
		throw OutOfBoundsException();
	return (pos);
}