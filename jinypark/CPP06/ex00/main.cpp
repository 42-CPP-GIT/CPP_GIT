/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:10:26 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/04 01:13:42 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Conversion conversion(argv[1]);
		std::cout << conversion;
	}
	return (0);
}