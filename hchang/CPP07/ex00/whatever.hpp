/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:18:43 by hchang            #+#    #+#             */
/*   Updated: 2022/12/01 20:49:36 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(const T a, const T b)
{
	return (a < b ? a : b);
}

template <typename T>
T	max(const T a, const T b)
{
	return (a > b ? a : b);
}

#endif
