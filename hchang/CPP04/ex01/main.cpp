/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:31:51 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 13:54:58 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void a()
{
	system("leaks Animal");
}

void test1()
{
	// Test 1
	Animal *A = new Cat();
	Animal *B = new Animal(*A);
	Animal *C = new Animal();
	*C = *A;

	delete C;
	delete B;
	delete A;
}

void test2()
{
	// Test 2
	Cat *A = new Cat();
	Cat *B = new Cat(*A);
	Cat *C = new Cat();
	*C = *A;

	delete A;
	delete B;
	delete C;
}

void subject()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;
}

int main()
{
	// atexit(a);

	subject();
	// test1();
	// test2();
	return 0;
}