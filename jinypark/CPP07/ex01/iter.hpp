/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:00:11 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/10 22:25:32 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, typename FUNC>
void iter(T* arr, unsigned int len, FUNC f)
{
	for (unsigned int i = 0; i < len; ++i)
	{
		f(arr[i]);
	}
}

// template <typename T>
// void print(T a)
// {
// 	std::cout << a << "\n";
// }


