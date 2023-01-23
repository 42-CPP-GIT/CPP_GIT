/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:51:03 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/23 20:36:27 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void) {

	std::cout << BOLDWHITE << "@@@@@@@@@@ [Int test] @@@@@@@@@@"
			  << RESET << std::endl;
	{
		int a = 2;
		int b = 3;
		std::cout << BOLDBLUE << "--- Swap Before ---"
			<< RESET << std::endl;
		std::cout << "a = " << a << ", b = " << b
				  << std::endl << std::endl;
		ft::swap(a, b);
		std::cout << BOLDCYAN << "--- Swap after ---"
			<< RESET << std::endl;
		std::cout << "a = " << a << ", b = " << b
				  << std::endl << std::endl;

		std::cout << BOLDGREEN << "--- Min test ---"
			<< RESET << std::endl;
		std::cout << "min( a, b ) = " << ft::min( a, b ) << std::endl << std::endl;

		std::cout << BOLDYELLOW << "--- Max test ---"
			<< RESET << std::endl;
		std::cout << "max( a, b ) = " << ft::max( a, b ) << std::endl << std::endl;
	}

	std::cout << BOLDWHITE << "@@@@@@@@@@ [String test] @@@@@@@@@@"
			  << RESET << std::endl;
	{
		std::string a = "chaine1";
		std::string b = "chaine2";
		std::cout << BOLDBLUE << "--- Swap Before ---"
			<< RESET << std::endl;
		std::cout << "a = " << a << ", b = " << b
				  << std::endl << std::endl;
		ft::swap(a, b);
		std::cout << BOLDCYAN << "--- Swap after ---"
			<< RESET << std::endl;
		std::cout << "a = " << a << ", b = " << b
				  << std::endl << std::endl;

		std::cout << BOLDGREEN << "--- Min test ---"
			<< RESET << std::endl;
		std::cout << "min( a, b ) = " << ft::min( a, b ) << std::endl << std::endl;

		std::cout << BOLDYELLOW << "--- Max test ---"
			<< RESET << std::endl;
		std::cout << "max( a, b ) = " << ft::max( a, b ) << std::endl << std::endl;
	}
	return 0;
}


