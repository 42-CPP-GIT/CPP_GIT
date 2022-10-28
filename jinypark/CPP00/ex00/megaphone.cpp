/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:52:12 by jinypark          #+#    #+#             */
/*   Updated: 2022/10/28 14:49:27 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
    if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; ++i)
	{
		int	str_len = strlen(argv[i]);
		for (int j = 0; j < str_len; ++j)
			argv[i][j] = toupper(argv[i][j]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
    return (0);
}
