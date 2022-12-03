/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:59:43 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 14:09:45 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	a()
{
	system("leaks Animal");
}

int	main()
{
	atexit(a);
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal	*test1 = new WrongAnimal();
	const WrongAnimal	*test2 = new WrongAnimal();
	const WrongCat		*test3 = new WrongCat();

	std::cout << "====== Wrong Animal ======\n";
	std::cout << test1->getType() << " " << std::endl;
	std::cout << test2->getType() << " " << std::endl;
	std::cout << test3->getType() << " " << std::endl;
	
	test1->makeSound();
	test2->makeSound();
	test3->makeSound();

	delete meta;
	delete j;
	delete i;
	delete test1;
	delete test2;
	delete test3;
	return (0);
}