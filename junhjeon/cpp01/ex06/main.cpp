/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:23:52 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/07 20:27:58 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl 		harl;
	std::string level = "";

	if (argc != 2)
		return (0);
	for (int i = 0; argv[1][i] != 0; i++)
		level += argv[1][i];
	harl.complain(level);

	return (0);
}
