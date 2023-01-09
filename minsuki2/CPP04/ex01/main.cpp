/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/09 17:22:54 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "color.h"

int	main(void) {

	{
		std::cout << std::endl << "--- PDF ---"
				  << std::endl << std::endl;
		const Animal*		j = new Dog();
		const Animal*		i = new Cat();

		delete j; j = NULL;
		delete i; i = NULL;
		std::system("leaks -q animal");
	}

	{
		std::cout << std::endl << GREEN << "--- Array of animals ---"
				  << RESET << std::endl << std::endl;

		Animal*		array_animals[10];
		for (int i = 0; i < 10; i++) {
			if (i % 2)
				array_animals[i] = new Dog();
			else
				array_animals[i] = new Cat();
		}
		std::cout << YELLOW << std::endl;
		for (int i = 0; i < 10; ++i) array_animals[i]->makeSound();
		std::cout << RESET << std::endl;
		for (int i = 0; i < 10; ++i) delete array_animals[i];
		std::cout << std::endl;
		std::system("leaks -q animal");
	}

	{
		std::cout << std::endl << BLUE << "--- Test for deep copy ---"
				  << RESET << std::endl << std::endl;
		Cat*	c = new Cat();
		std::cout << BLUE;
		std::cout << "Cat's 1st idea : "<< c->getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat's 2nd idea : "<< c->getBrain()->getIdea(1) << std::endl;
		std::cout << "Cat's 6th idea : "<< c->getBrain()->getIdea(5) << std::endl;
		c->getBrain()->setIdea(5, "I wanna play...");
		std::cout << "Cat's 6th idea : "<< c->getBrain()->getIdea(5) << std::endl;
		c->getBrain()->setIdea(5, "the game!?");
		std::cout << "Cat's 6th idea : "<< c->getBrain()->getIdea(5) << std::endl;
		std::cout << RESET << std::endl;
		delete c; c = NULL;
		std::system("leaks -q animal");
	}


	{
		std::cout << std::endl << MAGENTA << "--- Making a deep copy1 ---"
			<< RESET << std::endl << std::endl;
		Cat*	c1 = new Cat();
		Cat*	c2 = new Cat(*c1);
		std::cout << MAGENTA;
		c1->getBrain()->setIdea(99, "Gotta sleep now...");
		std::cout << "Cat1's last idea :" << c1->getBrain()->getIdea(99) << std::endl;
		std::cout << "Cat2's last idea :" << c2->getBrain()->getIdea(99) << std::endl;
		std::cout << RESET << std::endl;
		delete c1; c1 = NULL;
		delete c2; c2 = NULL;
		std::system("leaks -q animal");

	}

	{
		std::cout << std::endl << MAGENTA << "--- Making a deep copy2 ---"
			<< RESET << std::endl << std::endl;
		Dog*	d1 = new Dog();
		Dog*	d2 = new Dog(*d1);
		std::cout << MAGENTA;
		d1->getBrain()->setIdea(99, "Gotta sleep now...");
		std::cout << "Dog1's last idea :" << d1->getBrain()->getIdea(99) << std::endl;
		std::cout << "Dog2's last idea :" << d2->getBrain()->getIdea(99) << std::endl;
		std::cout << RESET << std::endl;
		delete d1; d1 = NULL;
		delete d2; d2 = NULL;
		std::system("leaks -q animal");
	}

	{
		std::cout << std::endl << CYAN << "--- Copy assignment operator1 ---"
				  << RESET << std::endl << std::endl;
		Dog*	d1 = new Dog();
		Dog*	d2 = new Dog();
		std::cout << CYAN;
		std::cout << "Dog1's first idea is "<< d1->getBrain()->getIdea(0) << std::endl;
		d1->getBrain()->setIdea(0, "something");
		std::cout << "Dog1's first idea is "<< d1->getBrain()->getIdea(0) << std::endl;

		*d2 = *d1;
		std::cout << "Dog2's first idea is "<< d2->getBrain()->getIdea(0) << std::endl;
		std::cout << RESET << std::endl;
		delete d1; d1 = NULL;
		delete d2; d2 = NULL;
		std::system("leaks -q animal");
	}

	{
		std::cout << std::endl << CYAN << "--- Copy assignment operator2 ---"
				  << RESET << std::endl << std::endl;
		Cat*	c1 = new Cat();
		Cat*	c2 = new Cat();

		*c2 = *c1;
		std::cout << CYAN;
		std::cout << "Cat2's last idea :" << c2->getBrain()->getIdea(99) << std::endl;
		std::cout << "Cat1's last idea :" << c1->getBrain()->getIdea(99) << std::endl;
		c1->getBrain()->setIdea(99, "No sleeping now!!!");
		std::cout << "Cat1's last idea :" << c1->getBrain()->getIdea(99) << std::endl;
		std::cout << "Cat2's last idea :" << c2->getBrain()->getIdea(99) << std::endl;
		std::cout << RESET << std::endl;
		delete c1; c1 = NULL;
		delete c2; c2 = NULL;
		std::system("leaks -q animal");
	}

	{
		std::cout << std::endl << CYAN << "--- self assignment ---"
				  << RESET << std::endl << std::endl;
		Cat*	c = new Cat();
		std::cout << CYAN;
		std::cout << "Cat's last idea : " << c->getBrain()->getIdea(99) << std::endl;
		*c = *c;
		std::cout << "Cat's last idea : " << c->getBrain()->getIdea(99) << std::endl;
		c->getBrain()->setIdea(99, "No sleeping now!!!");
		std::cout << "Cat's last idea : " << c->getBrain()->getIdea(99) << std::endl;
		std::cout << RESET << std::endl;
		delete c; c = NULL;
		std::system("leaks -q animal");
	}

	return 0;
}
