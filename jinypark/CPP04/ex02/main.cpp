/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:46:33 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/22 12:13:43 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	AAnimal ani;
	
	AAnimal *a[100];

	int i = 0;
	// int j = 0;
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
	
	// for (; j < 100; j++)
	// 	delete a[j];
	return (0);
}