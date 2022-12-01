/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:19:55 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/23 00:42:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHAT_EVER_HPP
# define WHAT_EVER_HPP

#include <iostream>

template <typename T>
void swap(T& n1, T& n2)
{
	T tmp;

	tmp = n1;
	n1 = n2;
	n2 = tmp;
}

template <typename T>
T min(T n1, T n2)
{
	if (n1 > n2)
		return n2;
	else if (n1 < n2)
		return n1;
	else
		return n2;
}

template <typename T>
T max(T n1, T n2)
{
	if (n1 < n2)
		return n2;
	else if (n1 > n2)
		return n1;
	else
		return n2;
}

#endif