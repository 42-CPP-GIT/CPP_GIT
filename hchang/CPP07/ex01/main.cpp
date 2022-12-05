/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:18:37 by hchang            #+#    #+#             */
/*   Updated: 2022/12/02 11:00:53 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	const int x	= 10;
	const int y	= 10;
	const int z	= 10;

	int			a[3] = {1, 2, 3};
	const int	aa[3] = {x, y, z};
	double		b[3] = {1.123, 2.123, 3.123};
	float		c[3] = {1.123f, 2.123f, 3.123f};
	std::string	d[3] = {"hchang", "42seoul", "CPP Module"};

	iter(a, 3, print);
	iter(aa, 3, print);
	iter(b, 3, print);
	iter(c, 3, print);
	iter(d, 3, print);
}
