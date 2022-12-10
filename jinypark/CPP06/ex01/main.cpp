/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:36:35 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/10 19:38:45 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

int main()
{
	Data		data;
	uintptr_t	ptr;
	Data*		ptrData;

	data.c = 'a';
	data.d = 2.2;
	data.i = 42;

	ptr = serialize(&data);
	ptrData = deserialize(ptr);

	std::cout << &data << ENDL;
	std::cout << ptr << ENDL;
	std::cout << "0x" << std::hex << ptr << std::dec << ENDL;
	std::cout << ptrData << ENDL;
	std::cout << data.c << data.d << data.i << ENDL;
	std::cout << ptrData->c << ptrData->d << ptrData->i << ENDL;

	return (0);
}