/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:45:24 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/03 16:59:29 by jinypark         ###   ########.fr       */
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
		std::cout << "sed: first argument may not be empty\n";
		return (0);
	}
	std::ifstream	file(argv[1]);
	if (file.fail()) 
		return (0);
	std::string		outStr(argv[1]);
	outStr.append(".replace");
	std::ofstream	out(outStr);
	if (out.fail())
	{
		file.close();
		return (0);
	}
	std::string		line;
	while (std::getline(file, line))
	{
		if (file.fail())
			break ;
			
		int		idx = 0;
		size_t	r;
		while ((r = line.substr(idx).find(argv[2])) != line.npos)
		{
			std::string	argvTo(argv[2]);
			out << line.substr(idx, r).append(argv[3]);
			idx += r + argvTo.length();
		}
		out << line.substr(idx) << std::endl;
	}
	file.close();
	out.close();
	return (0);
}