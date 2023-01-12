/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:18 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/09 17:15:12 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "color.h"
//
// static void _only_exit(void) {
//     std::system("leaks -q animal");
// }

int	main(void) {
	// atexit(_only_exit);

	{
		std::cout << std::endl
				  << YELLOW << "--- Project pdf: override가되었을 때 ---"
				  << RESET << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "Class Animal Type : " << meta->getType() << " " << std::endl;
		std::cout << "Class Dog Type : " << j->getType() << " " << std::endl;
		std::cout << "Class Cat Type : " << i->getType() << " " << std::endl;
		meta->makeSound();
		j->makeSound();
		i->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl;

	{
		std::cout << std::endl
				  << GREEN << "--- Objects are created as derived class ---"
				  << RESET << std::endl;
		const Animal* meta = new Animal();
		const Dog* j = new Dog();
		const Cat* i = new Cat();

		std::cout << "Class Animal Type : " << meta->getType() << " " << std::endl;
		std::cout << "Class Dog Type : " << j->getType() << " " << std::endl;
		std::cout << "Class Cat Type : " << i->getType() << " " << std::endl;
		meta->makeSound();
		j->makeSound();
		i->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << std::endl
				  << RED << "--- WrongAnimal Test: override가 되지 않았을 때 "
				  << RESET << std::endl;
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		std::cout << "Class Animal Type : " << meta->getType() << " " << std::endl;
		std::cout << "Class Cat Type : " << i->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound();  // WrongAnimal에서 virtual 키워드를 사용하지 않아서
						  // sound가WrongAnimal임
		delete meta;
		delete i;  // 소멸자가 한번만 불러짐
					// => WrongAnimal 소멸자가 virtual 아니기 때문에
	}

	{
		std::cout << std::endl
				  << YELLOW << "--- 정적으로도 upcasting 가능함 ---"
				  << RESET << std::endl;
		const Animal meta = Animal();
		const Animal j = Dog();
		const Animal i = Cat();

		std::cout << "Class Animal Type : " << meta.getType() << " " << std::endl;
		std::cout << "Class Dog Type : " << j.getType() << " " << std::endl;
		std::cout << "Class Cat Type : " << i.getType() << " " << std::endl;
		meta.makeSound();
		j.makeSound();
		i.makeSound();
	}

	return 0;
}
