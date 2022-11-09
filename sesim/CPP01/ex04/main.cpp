/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:01:31 by sesim             #+#    #+#             */
/*   Updated: 2022/11/09 15:28:27 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

static void	_stringReplace(std::string &str, std::string s1, std::string s2)
{
    std::string::size_type	find_idx(0);

    while (1)
    {
        find_idx = str.find(s1, find_idx);
        if (find_idx == std::string::npos)
            return;
        str.erase(find_idx, s1.length());
        str.insert(find_idx, s2);
        find_idx += s2.length();
    }
}

int main(int argc, char **argv)
{
    if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0')
	{
		std::cout << "error: Wrong number of arguments" << std::endl;
        return (1);
	}
	std::ifstream	readFile;
	std::ofstream	outFile;
    std::string		str;

	readFile.open(std::string(argv[1]));
    if (readFile.fail())
    {
		std::cout << "error: Cannot open input file" << std::endl;
		return (1);
    }
	std::getline(readFile, str, '\0');
	readFile.close();
    _stringReplace(str, std::string(argv[2]), std::string(argv[3]));
	outFile.open((std::string(argv[1]) + ".replace"));
    outFile << str;
    outFile.close();
	return (0);
}
