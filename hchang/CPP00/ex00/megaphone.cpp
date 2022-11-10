/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:18:04 by hchang            #+#    #+#             */
/*   Updated: 2022/11/01 12:46:29 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char** argv) {
  std::string str;
  int a;

  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {
    for (int i = 1; i < argc; i++) str += std::string(argv[i]);
    for (int j = 0; j < (int)str.size(); j++) str[j] = std::toupper(str[j]);
    std::cout << str;
  }
  std::cout << std::endl;
  return (0);
}
