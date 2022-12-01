/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:26:44 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/06 21:23:47 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Address of string   : " << &string << "\n";
	std::cout << "Address of stringPTR: " << stringPTR << "\n";
	std::cout << "Address of stringREF: " << &stringREF << "\n";
	std::cout << "------------------------------------" << "\n";
	std::cout << "Value of string   : "<< string << "\n";
	std::cout << "Value of stringPTR: "<< *stringPTR << "\n";
	std::cout << "Value of stringREF: "<< stringREF << "\n";
	return (0);
}


