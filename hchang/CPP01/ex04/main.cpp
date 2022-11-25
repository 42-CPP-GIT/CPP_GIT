/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:05:14 by hchang            #+#    #+#             */
/*   Updated: 2022/11/07 21:38:35 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void stringReplace(std::string &str, std::string s1, std::string s2)
{
    const size_t s1_len(s1.length());
    std::string::size_type find_idx(0);

    while (1)
    {
        find_idx = str.find(s1, find_idx);
        if (find_idx == std::string::npos)
            return;
        str.erase(find_idx, s1_len);
        str.insert(find_idx, s2);
        find_idx += s2.length();
    }
}

int main(int argc, char **argv)
{
    std::ifstream readFile;
    std::ofstream outFile;
    std::string str;

    if (argc != 4 || argv[1][0] == '\0')
        return (0);
    readFile.open(argv[1]);
    if (readFile.is_open())
    {
        std::getline(readFile, str, '\0');
        readFile.close();
    }
	else
		return (1);
    outFile.open(std::string(argv[1]) + ".replace");
    stringReplace(str, std::string(argv[2]), std::string(argv[3]));
    outFile << str;
    outFile.close();
}
