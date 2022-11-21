/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:31:51 by hchang            #+#    #+#             */
/*   Updated: 2022/11/21 14:39:42 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void a()
{
	system("leaks Animal");
}

int main()
{
	// atexit(a);
	
	// deep copy check
	Animal test1;
	Animal test2;
	
	test1 = test2;
	
	// Subject
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;
	


	// Animal *A = new Cat();
	// Animal *B = new Animal(*A);
	// Animal *C = new Animal();
	// *C = *A;

	// delete C;
	// delete B;
	// delete A;
	
	// Cat *A = new Cat();
	// Cat *B = new Cat(*A);
	// Cat *C = new Cat();
	// *C = *A;

	// delete A;
	// delete B;
	// delete C;


	return 0;
}