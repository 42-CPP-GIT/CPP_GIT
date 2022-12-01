/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:43:53 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/18 18:34:21 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	Dog dog1;

	dog1.getBrain()->getIdeas()[0] = "i am dog1...?";
	d->getBrain()->getIdeas()[0] = "i am dog...?";
	c->getBrain()->getIdeas()[0] = "i am cat...?";

	Dog d2 = dog1;
	std::cout << " Before Change Ideas" << std::endl;
	std::cout << "dog1 : " << dog1.getBrain()->getIdeas()[0] << std::endl;
	std::cout << "dog2 : " << d2.getBrain()->getIdeas()[0] << std::endl;
	
	d2.getBrain()->getIdeas()[0] = "yes i am dog2 !";
	
	std::cout << " After Change Ideas" << std::endl;
	std::cout << "dog 1 : " << dog1.getBrain()->getIdeas()[0] << std::endl;
	std::cout << "dog 2 : " << d2.getBrain()->getIdeas()[0] << std::endl;


	delete d;//should not create a leak
	delete c;

	//system("leaks a.out");
	return 0;
}
