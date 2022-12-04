/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:22:39 by sesim             #+#    #+#             */
/*   Updated: 2022/12/01 11:39:16 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
void	iter(T *array, size_t n, void(*f)(T&))
{
	for (size_t i = 0; i < n; ++i)
		f(array[i]);
}

template <typename T>
void	iter(const T *array, size_t n, void(*f)(const T&))
{
	for (size_t i = 0; i < n; ++i)
		f(array[i]);
}

template <typename T>
void	print1(const T& a)
{
	std::cout << a << std::endl;
}

template <typename T>
void	print1(T& a)
{
	std::cout << a << std::endl;
}