/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:01:59 by sesim             #+#    #+#             */
/*   Updated: 2022/11/08 10:03:24 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string	res;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; ++i)
		{
			for (int k = 0; k < (int)strlen(av[i]); ++k)
				res += std::toupper(av[i][k]);
		}
		std::cout << res;
	}
	std::cout << std::endl;
	return (0);
}
