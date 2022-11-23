/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:29:34 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/23 20:06:27 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


void a()
{
	system("leaks Animal");
}
int main()
{
	// atexit(a);
	// 다형성
	// Subject
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	const WrongAnimal* t = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << t->getType() << " " << std::endl;
	t->makeSound();

	delete i;
	delete j;
	delete meta;
	delete t; // 왜 animal만 delete but no leaks
	
	return 0;	
}
