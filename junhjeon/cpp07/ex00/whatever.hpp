/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:13:55 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/25 14:36:28 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void swap(T *a, T*b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<typename T>
T& min(T &a, T &b)
{
	if ( a < b )
		return (a);
	return (b);
}

template<typename T>
T& max(T &a, T &b)
{
	if ( a > b )
		return (a);
	return (b);
}

