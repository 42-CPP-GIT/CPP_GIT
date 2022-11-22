/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:46:33 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 18:44:38 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void a()
{
	system("leaks a.out");
}
int main()
{
	// atexit(a);
	// // const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// i->getBrain()->showIdeas();
	// i->getBrain()->setIdeas("hi");
	// i->getBrain()->showIdeas();
	// // delete j;//should not create a leak
	// delete i;

	Animal *a[100];

	int i = 0;
	int j = 0;
	for (; i < 50; i++)
		a[i] = new Cat();
	for (; i < 100; i++)
		a[i] = new Cat();

	
	for (; j < 100; j++)
		delete a[j];
	Cat *A = new Cat();
	Cat *B = new Cat(*A);
	Cat *C = new Cat();
	*C = *A;
	delete C;
	delete B;
	delete A;
	return (0);
}