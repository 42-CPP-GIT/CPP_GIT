/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:30:59 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/02 13:59:43 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManager.hpp"
#include "Replace.hpp"

int main(int argc, char **argv) 
{
	if (argc == 4)
	{
		FileManager fm(argv[1]);
		Replace rp(fm, argv[2], argv[3]);
		rp.execute();
	}
	else
		std::cout << "Error :arguments" << std::endl;
}