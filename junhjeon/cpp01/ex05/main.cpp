/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:23:52 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/01 18:02:17 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl 		harl;
	std::string level = "";

	int j = argc;
	j = 1;
	for (int i = 0; argv[1][i] != 0; i++)
		level += argv[1][i];
	harl.complain(level);

	return (0);
}
