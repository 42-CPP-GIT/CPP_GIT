/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:10:18 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/20 20:29:08 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char* argv[]) {

	try {
		if (argc != 2) {
			throw Conversion::ArgumentCountsException();
		}
		else if (argv[1][0] == 'f' && argv[1][1] == '\0') {
			throw Conversion::JustFloatCharException();
		}
		char*			pos;
		double			val(strtod(argv[1], &pos));
		pos == NULL	? throw Conversion::EndPointerException() : false;
		const std::string& end(pos);

		Conversion		con(val, end);
		con.printChar();
		con.printInt();
		con.printFloat();
		con.printDouble();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << '\n';
	}
}
