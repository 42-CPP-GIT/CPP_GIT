/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:29:34 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/10 19:40:31 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	//Dog* xx = new Dog();
	//std::cout << xx->getType() << " <- type" << std::endl;
	//std::cout << xx->getName() << " <- name" << std::endl;

	//xx->makeSound();
	//delete xx;
	//Dog* yy = new Animal();

	//Cat* yy = new Cat();
	//std::cout << yy->getType() << " " << std::endl;
	//yy->makeSound();
	//delete yy;

	//Animal* hey = new Dog[5];
	//std::cout << hey->getType() << std::endl;
	//hey[0].makeSound();
	//delete [] hey;


	Dog* why = new Dog[5];
	std::cout << why->getType() << std::endl;
	std::cout << why[2].getName() << std::endl;
	why->makeSound();

	//const Animal* meta = new Animal();
	//const Animal* j = new Dog();
	//const Animal* i = new Cat();
	
	//std::cout << j->getType() << " " << std::endl;
	//std::cout << i->getType() << " " << std::endl;
	
	//i->makeSound(); //will output the cat sound!
	//j->makeSound();
	//meta->makeSound();

	//delete meta;
	//delete i;
	//delete j;

	return 0;	
}