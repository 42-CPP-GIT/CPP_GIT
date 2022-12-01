/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:10:40 by junoh             #+#    #+#             */
/*   Updated: 2022/11/11 14:38:59 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>



int main(int argc, char *argv[])
{   
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARBLE FEEDBACK NOISE *";
    std::string str;
    for(int i = 1; i < argc; i++){
        for (int j = 0; argv[i][j] != 0; j++){
            str += std::toupper(argv[i][j]);
        }
    }
    std::cout << str <<std::endl;
    return (0);
}