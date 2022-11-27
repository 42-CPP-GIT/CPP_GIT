/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:48:23 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/23 19:28:22 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void iter (T *ary, unsigned int length, void(*fptr) (T &))
{
	for (unsigned int i = 0; i < length; i ++)
	{
		fptr(ary[i]);
		//(*fptr)(ary[i]);
	}
}

template <typename T>
void	print_t (T& a)
{
	std::cout << a << std::endl;
}
