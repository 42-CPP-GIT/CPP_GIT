/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:18:43 by hchang            #+#    #+#             */
/*   Updated: 2022/12/02 11:44:56 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *arrayAd, unsigned int len, void(*f)(T&))
{
	for (unsigned int i = 0; i < len; i++)
		f(arrayAd[i]);
	std::cout << std::endl;
}

template <typename T>
void	iter(const T *arrayAd, unsigned int len, void(*f)(const T&))
{
	for (unsigned int i = 0; i < len; i++)
		f(arrayAd[i]);
	std::cout << std::endl;
}

template <typename T>
void	print(T element)
{
	std::cout << element << " ";
}

template <typename T>
void	print(const T& element)
{
	std::cout << element << " ";
}

#endif
