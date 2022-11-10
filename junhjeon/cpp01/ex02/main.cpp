/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:24:52 by junhjeon          #+#    #+#             */
/*   Updated: 2022/10/31 18:35:20 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str : " << &str << std::endl;
	std::cout << "ptr : " << stringPTR << std::endl;
	std::cout << "ref : " << &stringREF << std::endl;

	std::cout << "str : " << str << std::endl;
	std::cout << "ptr : " << *stringPTR << std::endl;
	std::cout << "ref : " << stringREF << std::endl;

	stringREF = "BYE THIS IS NOT BRAIN";

	std::cout << "str : " << str << std::endl;
	std::cout << "ptr : " << *stringPTR << std::endl;
	std::cout << "ref : " << stringREF << std::endl;

	str = "HI THIS IS BRAIN";

	std::cout << "str : " << &str << std::endl;
	std::cout << "ptr : " << stringPTR << std::endl;
	std::cout << "ref : " << &stringREF << std::endl;

	std::cout << "str : " << str << std::endl;
	std::cout << "ptr : " << *stringPTR << std::endl;
	std::cout << "ref : " << stringREF << std::endl; 

	*stringPTR = "BYE THIS IS NOT BRAIN";

	std::cout << "str : " << &str << std::endl;
	std::cout << "ptr : " << stringPTR << std::endl;
	std::cout << "ref : " << &stringREF << std::endl;

	std::cout << "str : " << str << std::endl;
	std::cout << "ptr : " << *stringPTR << std::endl;
	std::cout << "ref : " << stringREF << std::endl;


	return (0);
}
