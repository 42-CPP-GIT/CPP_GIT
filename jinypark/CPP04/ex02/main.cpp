/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:46:33 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 16:26:25 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void A()
{
	system("leaks a.out");
}

int main()
{
	// AAnimal b;
	atexit(A);
	AAnimal *a[100];

	int i = 0;
	int j = 0;
	for (; i < 50; i++)
		a[i] = new Dog();
	for (; i < 100; i++)
		a[i] = new Cat();

	AAnimal* newAnimal = new Dog(*(dynamic_cast<Dog *>(a[0])));

	a[0]->getBrain()->showIdeas();
	newAnimal->getBrain()->showIdeas();

	newAnimal->getBrain()->setIdeas("HELLO!");
	a[0]->getBrain()->setIdeas("BYE!");
	std::cout << "----------------------------------\n";
	a[0]->getBrain()->showIdeas();
	newAnimal->getBrain()->showIdeas();

	for (; j < 100; j++)
		delete a[j];
	delete newAnimal;
	Dog hey;
	{
		Dog tmp = hey;
	}
	hey.getBrain()->showIdeas();
	return (0);
}