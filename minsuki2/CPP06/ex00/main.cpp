/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:10:18 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/19 19:32:11 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "" << '\n';
		return
	}
	try {
	}
	catch (std::exception& e){
		std::cerr << e.what() << '\n';
	}
	const char* string = argv[0];

	std::cout << static_cast<float>(std::atof("nan")) << std::endl;
	return 0;

}
