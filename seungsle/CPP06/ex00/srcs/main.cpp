/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:22:03 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/21 03:32:45 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Convert cvt(argv[1]);
		cvt.toChar();
		cvt.toInt();
		cvt.toFloat();
		cvt.toDouble();
	}
}