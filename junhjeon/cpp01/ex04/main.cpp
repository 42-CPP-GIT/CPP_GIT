/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:24:15 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/03 20:51:19 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	std::string str = "";
	std::string backup = "";
	std::string s1 = "";
	std::string s2 = "";

	if (argc != 4)
		return (0);

	for (int i = 0; argv[1][i] != 0; i++)
		str += argv[1][i];
	for (int i = 0; argv[2][i] != 0; i++)
		s1 += argv[2][i];
	for (int i = 0; argv[3][i] != 0; i++)
		s2 += argv[3][i];

	if (s1 == "")
	{
		std::cout << "can't replace \"\"" << std::endl;
		return (0);
	}
	std::ifstream fin(argv[1]);
	if (fin.fail())
		return (0);
	str += ".replace";
	//char	outfile[str.size() + 9];
	//std::strcpy(outfile, str.c_str());
	std::ofstream fout(str);

	str.clear();
	fin.seekg(0, std::ios::end);
	int size = fin.tellg();
	str.resize(size);
	fin.seekg(0, std::ios::beg);
	fin.read(&str[0], size);

	int idx(0);
	int	idx_before(0);
	if (str.find(s1, idx) == std::string::npos)
			fout << str;
	else
	{
		while (str.find(s1, idx) != std::string::npos)
		{
			idx_before = idx;
			idx = str.find(s1, idx);
			backup += str.substr(idx_before, idx - idx_before);
			backup += s2;
			idx += s1.size();
			idx_before += s1.size();
		}
		backup += str.substr(idx);
		fout << backup;
	}
	fin.close();
	fout.close();
}