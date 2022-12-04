/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:08:58 by sesim             #+#    #+#             */
/*   Updated: 2022/12/01 11:31:51 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	const int	arr1[10] = {1, 2, 3, 4,};
	int			arr2[10] = {1, 2, 3, };

	::iter(arr1, (sizeof(arr1) / sizeof(arr1[0])), print1);
	::iter(arr2, (sizeof(arr2) / sizeof(arr2[0])), print1);
	return (0);
}