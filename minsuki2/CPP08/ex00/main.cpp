/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:31:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/25 07:59:31 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <set>
#include "easyfind.hpp"

int main(void) {
	std::cout << std::endl
			  << BOLDCYAN << "----[CASE 1] : vector----" << RESET << std::endl;
	try {
		std::vector<int> v;
		for (int i = -5; i < 10; i++) { v.push_back(i); }

		int n(5);
		std::cout << GREEN << "▷ Normal : " << n << RESET << std::endl;
		std::cout << *(ft::easyfind(v, n)) << " <= "
				  << "v[" << std::distance(v.begin(), ft::easyfind(v, n)) << ']'
				  << std::endl;
		n = 12;
		std::cout << RED << "▷ Error : " << n << RESET << std::endl;
		std::cout << *(ft::easyfind(v, n)) << " => v["
				  << std::distance(v.begin(), ft::easyfind(v, n)) << ']'
				  << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl
			  << BOLDBLUE << "----[CASE 2] : deque----" << RESET << std::endl;
	try {
		std::deque<int> d;
		for (int i = -5; i < 10; i++) { d.push_back(i); }

		int n(-1);
		std::cout << GREEN << "▷ Normal : " << n << RESET << std::endl;
		std::cout << *(ft::easyfind(d, n)) << " <= "
				  << "d[" << std::distance(d.begin(), ft::easyfind(d, n)) << ']'
				  << std::endl;

		n = -6;
		std::cout << RED << "▷ Error : " << n << RESET << std::endl;
		std::cout << *(ft::easyfind(d, n)) << " <= "
				  << "d[" << std::distance(d.begin(), ft::easyfind(d, n)) << ']'
				  << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl
			  << BOLDYELLOW << "----[CASE 3] : list----" << RESET << std::endl;
	try {
		std::list<int> l;
		for (int i = -5; i < 10; i++) { l.push_back(i); }

		int n(2);
		std::cout << GREEN << "▷ Normal : " << n << RESET << std::endl;
		std::cout << *(ft::easyfind(l, n)) << " <= "
				  << "l[" << std::distance(l.begin(), ft::easyfind(l, n)) << ']'
				  << std::endl;

		n = 2147483647;
		std::cout << RED << "▷ Error : " << n << RESET << std::endl;
		std::cout << *(ft::easyfind(l, n)) << " <= "
				  << "l[" << std::distance(l.begin(), ft::easyfind(l, n)) << ']'
				  << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl
			  << BOLDYELLOW << "----[CASE 4] : set----" << RESET << std::endl;
	try {
		std::set<int> s;
		for (int i = -5; i < 10; i++) { s.insert(i); }

		int n(5);
		std::cout << GREEN << "▷ Normal : " << n << RESET << std::endl;
		std::cout << *(ft::easyfind(s, n)) << " <= "
				  << "s[" << std::distance(s.begin(), ft::easyfind(s, n)) << ']'
				  << std::endl;

		n = 10;
		std::cout << RED << "▷ Error : " << n << RESET << std::endl;
		std::cout << *(ft::easyfind(s, n)) << " <= "
				  << "s[" << std::distance(s.begin(), ft::easyfind(s, n)) << ']'
				  << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}
