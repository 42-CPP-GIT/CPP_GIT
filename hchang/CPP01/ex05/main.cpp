/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:00:06 by hchang            #+#    #+#             */
/*   Updated: 2022/11/05 15:21:01 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl h;
	std::cout << "=======DEBUG=======" << std::endl;
	h.complain("DEBUG");
	std::cout << "=======INFO=======" << std::endl;
	h.complain("INFO");
	std::cout << "=======WARNING=======" << std::endl;
	h.complain("WARNING");
	std::cout << "=======ERROR=======" << std::endl;
	h.complain("ERROR");
	std::cout << "=======TYPO=======" << std::endl;
	h.complain("ERRORsdf");
}