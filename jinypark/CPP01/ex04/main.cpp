/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:45:24 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/09 14:10:54 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (*argv[2] == '\0')
	{
		std::cout << "replace: first argument may not be empty" << std::endl;
		return (0);
	}
	std::ifstream	file(argv[1]);
	if (file.fail()) 
		return (0);
	std::ofstream	out(std::string(argv[1]) + ".replace");
	if (out.fail())
	{
		file.close();
		return (0);
	}
	std::string		line;
	std::getline(file, line, '\0');
	size_t	idx;
	while ((idx = line.find(argv[2])) != line.npos)
	{
		std::string	s1(argv[2]);
		out << line.substr(0, idx) << (argv[3]);
		line = line.substr(idx + s1.length());
	}
	out << line;
	file.close();
	out.close();
	return (0);
}