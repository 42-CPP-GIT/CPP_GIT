/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:31:51 by hchang            #+#    #+#             */
/*   Updated: 2022/11/18 16:57:49 by hchang           ###   ########.fr       */
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
	int cnt = 4;

	Animal *x[cnt];
	// Animal qq;
	// Animal *qq = new Animal();
	for (int i = 0; i < cnt; i++)
	{
		std::cout << "i = " << i << std::endl;
		if (i % 2 == 0)
			x[i] = new Dog();
		else
			x[i] = new Cat();
		std::cout << " ▶︎ type : " << x[i]->getType() << std::endl;
		x[i]->makeSound();
		std::cout << "================== " << std::endl;
	}
	Brain *myBrain = new Brain();
	Animal *y = new Dog(myBrain);
	delete x[0];
	x[0] = y;

	std::cout << "our test : " << x[0]->getType() << std::endl;
	x[0]->noBrain();
	
	for (int i = 0; i < cnt; i++)
		delete x[i];
	// Animal *y[cnt];
	// y[0] = new Dog();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();


	// delete j;//should not create a leak
	// delete i;

	return 0;
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
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// std::cout << meta->getType() << " " << std::endl;
	
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();

	// delete i;
	// delete j;
	// delete meta;

	// return 0;	
}
