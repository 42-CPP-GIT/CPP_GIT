/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:00:11 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/20 21:42:44 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template <typename T>
void printT(const T& t)
{
	std::cout << t << std::endl;
	return;
}

template <typename T, typename F>
void iter(T* arr, unsigned int len, F f)
{
	for (unsigned int i = 0; i < len; ++i)
	{
		f(arr[i]);
	}
}

// template <typename T>
// void iter(const T* arr, unsigned int len, void (*f)(const T&))
// {
// 	for (unsigned int i = 0; i < len; ++i)
// 	{
// 		f(arr[i]);
// 	}
// }

#endif



