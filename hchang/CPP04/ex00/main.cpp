/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:29:34 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/16 11:41:40 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	// Anin


	// Dog* xx = new Dog();
	// std::cout << xx->getType() << " <- type" << std::endl;
	// std::cout << xx->getName() << " <- name" << std::endl;

	// xx->makeSound();
	// delete xx;
	// Dog* yy = new Animal();

	//Cat* yy = new Cat();
	//std::cout << yy->getType() << " " << std::endl;
	//yy->makeSound();
	//delete yy;

	// Animal* hey = new Dog[5];
	// for (int i = 0; i < 5; i++)
	// {
	// 	std::cout << hey[i].getType() << std::endl;
	// 	hey[i].makeSound();
	// }
	// delete [] hey;


	// Dog* why = new Dog[5];
	// std::cout << why->getType() << std::endl;
	// std::cout << why[2].getName() << std::endl;
	// why->makeSound();

	// const Dog* hey = new Animal();
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	return 0;	
}
