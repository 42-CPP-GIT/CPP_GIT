/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:04:54 by hchang            #+#    #+#             */
/*   Updated: 2023/08/07 19:24:27 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe	test((argc - 1), &(argv[1]));
		test.sort();
		test.printRes();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}