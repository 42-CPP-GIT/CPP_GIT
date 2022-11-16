/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:41:44 by junoh             #+#    #+#             */
/*   Updated: 2022/11/11 14:39:43 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook PhoneBook;
    std::string command;
    
    while (1)
    {
        std::cout << "Input your command sir (ADD, SEARCH, EXIT)" << std::endl;
        if (!std::getline(std::cin, command))
        {
            std::cout << "EOF Detected" << std::endl;
            exit(1);
        }
        if (command.compare("ADD") == 0)
        {
            PhoneBook.add();   
        }
        else if (command.compare("SEARCH") == 0)
        {
            PhoneBook.search();
        }    
        else if (command.compare("EXIT") == 0)
        {
            return(0);
        }  
    }
}