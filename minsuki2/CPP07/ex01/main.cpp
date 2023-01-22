/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:51:03 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/22 21:56:11 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {

	std::cout << BOLDWHITE << "@@@@@@@@@@ [Int array test] @@@@@@@@@@"
			  << RESET << std::endl;
	{
		int arr[] = {0, 1, 2, 3, 4};
		const int c_arr[] = {5, 6, 7, 8, 9};
		std::cout << BOLDBLUE << "--- just array Before ---"
				  << RESET << std::endl;
		iter(arr, 5, showElement<int>);
		// iter(arr, 5, showElement);

		std::cout << BOLDCYAN << "--- const array Before ---"
			<< RESET << std::endl;
		iter(c_arr, 5, showElement<int>);
		// iter(c_arr, 5, showElement);
	}

	std::cout << BOLDWHITE << "@@@@@@@@@@ [String array test] @@@@@@@@@@"
			  << RESET << std::endl;
	{
		std::string	arr[] = {"AAA", "BBB", "CCC"};
		const std::string	c_arr[] = {"DDD", "EEE", "FFF"};

		std::cout << BOLDBLUE << "--- just array Before ---"
				  << RESET << std::endl;
		iter(arr, 3, showElement<std::string>);
		// iter(arr, 3, showElement);

		std::cout << BOLDCYAN << "--- const array Before ---"
			<< RESET << std::endl;
		iter(c_arr, 3, showElement<std::string>);
		// iter(c_arr, 3, showElement);
	}
	return 0;
}
