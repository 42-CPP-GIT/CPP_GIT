/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:34:15 by hchang            #+#    #+#             */
/*   Updated: 2022/11/29 17:12:35 by hchang           ###   ########.fr       */
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
	Data*		C = new Data;
	uintptr_t	B;

	A->_data = 10;
	B = serialize(A);
	std::cout << A << std::endl;
	std::cout << "0x" << std::hex << B << std::endl;

	C = deserialize(B);

	std::cout << A << std::endl;
	std::cout << "0x" << std::hex << B << std::endl;
	std::cout << C << std::endl;

	std::cout << A->_data << std::endl;
	std::cout << C->_data << std::endl;
}