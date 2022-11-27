/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:46:33 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/27 16:56:48 by jinypark         ###   ########.fr       */
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
	atexit(a);
	Animal *a[100];

	int i = 0;
	for (; i < 50; ++i)
		a[i] = new Dog();
	for (; i < 100; ++i)
		a[i] = new Cat();

	Animal* newAnimal = new Dog(*(dynamic_cast<Dog *>(a[0])));

	a[0]->getBrain()->showIdeas();
	newAnimal->getBrain()->showIdeas();

	newAnimal->getBrain()->setIdeas("HELLO!");
	a[0]->getBrain()->setIdeas("BYE!");
	std::cout << "----------------------------------\n";
	a[0]->getBrain()->showIdeas();
	newAnimal->getBrain()->showIdeas();

	for (int j = 0; j < 100; ++j)
		delete a[j];
	delete newAnimal;
	return (0);
}