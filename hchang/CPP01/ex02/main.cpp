/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:12 by hchang            #+#    #+#             */
/*   Updated: 2022/11/05 15:52:51 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Your program has to print:" << std::endl; 
    std::cout << "[1]. string address           : " << &str << std::endl;
    std::cout << "[2]. string pointer address   : " << stringPTR << std::endl;
    std::cout << "[3]. string reference address : " << &stringREF << std::endl;

    std::cout << "And then::" << std::endl; 
    std::cout << "[1]. The value of the string           : " << str << std::endl;
    std::cout << "[2]. The value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "[3]. The value pointed to by stringREF : " << stringREF << std::endl;
}
