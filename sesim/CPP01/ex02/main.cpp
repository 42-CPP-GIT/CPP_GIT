/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:55:59 by sesim             #+#    #+#             */
/*   Updated: 2022/11/09 15:17:07 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	stringORIG = "HI THIS IS BRAIN";
	std::string	*stringPTR(&stringORIG);
	std::string &stringREF(stringORIG);

	std::cout << "===== addrress =====" << std::endl;
	std::cout << &stringORIG << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "===== value =====" << std::endl;
	std::cout << stringORIG << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}