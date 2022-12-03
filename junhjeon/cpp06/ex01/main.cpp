/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:53:44 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/23 15:03:21 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t> (ptr));
}

Data *deserialize(uintptr_t raw)
{
	return ((reinterpret_cast<Data *> (raw)));
}

int main( void )
{
	struct Data sample;
	sample._name = "sample";
	uintptr_t	 ptr;
	struct Data *d_ptr;

	std::cout << "data memeber " << std::endl;
	std::cout << sample._name << std::endl;
	std::cout << "sample ptr : " << &sample << std::endl;

	std::cout << " serialize........ " << std::endl;
	ptr = serialize(&sample);
	std::cout << "serialize ptr : " << std::hex << ptr << std::endl;

	std::cout << " deserialize......." << std::endl;
	d_ptr = deserialize(ptr);
	std::cout << "member check......." << std::endl;
	std::cout << (*d_ptr)._name << std:: endl;

	return (0);
}
