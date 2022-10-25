/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:18:04 by hchang            #+#    #+#             */
/*   Updated: 2022/10/21 16:44:00 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
#include <iostream>

int main(int argc, char** argv)
{
    std::string str;
	auto a;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			str += std::string(argv[i]);
		for (int j = 0; j < str.size(); j++)
			str[j] = std::toupper(str[j]);
		std::cout << str << std::endl;
	}
	return (0);
}
