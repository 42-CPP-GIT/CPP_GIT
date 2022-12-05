/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:34:15 by hchang            #+#    #+#             */
/*   Updated: 2022/12/01 16:11:40 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef struct s_cast
{
	int _data;
}	Data;

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data*		A = new Data;
	uintptr_t	B = 0;
	Data*		C = new Data;

	std::cout << "======[Begin]======" << std::endl;
	std::cout << "A : " << A << std::endl;
	std::cout << "B : 0x" << std::hex << B << std::endl;

	std::cout << "======[Serialize]======" << std::endl;
	A->_data = 10;
	B = serialize(A);
	std::cout << "A : " << A << std::endl;
	std::cout << "B : 0x" << std::hex << B << std::endl;

	std::cout << "======[Deserialize]======" << std::endl;
	C = deserialize(B);
	std::cout << "A : " << A << std::endl;
	std::cout << "B : 0x" << std::hex << B << std::endl;
	std::cout << "C : " << C << std::endl;

	std::cout << "======[Data Check]======" << std::endl;
	std::cout << "A->_data : " << A->_data << std::endl;
	std::cout << "C->_data : " << C->_data << std::endl;
}
