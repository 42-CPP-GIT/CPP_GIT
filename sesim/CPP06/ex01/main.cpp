/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:48:14 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 18:36:03 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	a(void)
{
	system("leaks convert");
}

typedef struct	s_data
{
	int	num;
}	Data;

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	Data		A;
	Data*		B;
	uintptr_t	ptr(0);

	A.num = 10;
	std::cout << ">> Begin Address\n";
	std::cout << "A : " << &A << std::endl;
	std::cout << "B : " << B << std::endl;
	std::cout << "ptr : 0x" << std::hex << ptr << std::dec << std::endl;

	std::cout << ">> Serialize\n";
	ptr = serialize(&A);
	std::cout << "A : " << &A << std::endl;
	std::cout << "B : " << B << std::endl;
	std::cout << "ptr : 0x" << std::hex << ptr << std::dec << std::endl;

	std::cout << ">> Deserialize\n";
	B = deserialize(ptr);
	std::cout << "A : " << &A << std::endl;
	std::cout << "B : " << B << std::endl;
	std::cout << "ptr : 0x" << std::hex << ptr << std::dec << std::endl;

	std::cout << ">> Data\n";
	std::cout << "A : " << A.num << std::endl;
	std::cout << "B : " << B->num << std::endl;
}
