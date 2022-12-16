/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:00:11 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/16 13:49:25 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
	return;
}

template <typename T, typename FUNC>
void iter(T* arr, unsigned int len, FUNC f)
{
	for (unsigned int i = 0; i < len; ++i)
	{
		f(arr[i]);
	}
}



