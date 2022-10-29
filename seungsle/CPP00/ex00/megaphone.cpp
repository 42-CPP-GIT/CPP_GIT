/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:23:11 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/29 15:20:02 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string argvString(argv[i]);
			for (std::string::iterator it = argvString.begin(); it != argvString.end(); ++it)
				*it = toupper(*it);
			std::cout << argvString;
		}
		std::cout << std::endl;
	}
	return (0);
}
