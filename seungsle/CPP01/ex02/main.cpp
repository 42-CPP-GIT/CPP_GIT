/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:07:40 by seungsle          #+#    #+#             */
/*   Updated: 2022/10/26 14:14:26 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable." << std::endl;
	std::cout << "The memory address held by " << stringPTR << std::endl;
	std::cout << "The memory address held by " << &stringREF << std::endl;
	std::cout << "The value of the string variable." << std::endl;
	std::cout << "The value pointed to by " << *stringPTR << std::endl;
	std::cout << "The value pointed to by " << stringREF << std::endl;
}