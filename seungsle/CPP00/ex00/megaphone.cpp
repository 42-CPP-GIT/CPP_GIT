/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:23:11 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/27 14:37:48 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" ;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; j < (int)strlen(argv[i]); j++)
			{
				std::cout << (char)toupper(argv[i][j]);
			}
		}
		std::cout << "\n";
	}
	return (0);
}

// char * -> string
// typecast
// https://doitnow-man.tistory.com/215