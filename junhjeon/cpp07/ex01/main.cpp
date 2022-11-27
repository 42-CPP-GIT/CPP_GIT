/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:10:11 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/23 19:23:38 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main()
{
	int	i_ary[3] = {1, 2, 3};
	double d_ary[3] = {1.1, 2.2, 3.3};
	float  f_ary[3] = {1.1f, 2.2f, 3.3f};
	std::string s_ary[3] = {"hello", "world", "!"};

	iter(i_ary, 3, print_t);
	iter(&d_ary[0], 3, print_t);
	iter(&f_ary[0], 3, print_t);
	iter(&s_ary[0], 3, print_t);

	return (0);
}
