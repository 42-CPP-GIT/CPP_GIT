/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:23:11 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/01 14:40:42 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string str;
		for (int i = 1; i < argc; i++)
			str += std::string(argv[i]);
		for (size_t i = 0; i < str.length(); i++)
			str[i] = std::toupper(str[i]);
		std::cout << str;
		// for (int i = 1; i < argc; i++)
		// {
		// 	std::string argvString(argv[i]);
		// 	for (std::string::iterator it = argvString.begin(); it != argvString.end(); ++it)
		// 		*it = std::toupper(*it);
		// 	std::cout << argvString;
		// }
		std::cout << std::endl;
	}
	return (0);
}
