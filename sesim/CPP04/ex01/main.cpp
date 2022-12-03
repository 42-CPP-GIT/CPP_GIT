/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:59:43 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 14:46:58 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void	a()
{
	system("leaks Animal");
}

void	testA(void)
{
	std::cout << "======= TEST A ======" << std::endl;
	Animal	*A = new Cat();
	Animal	*B = new Animal(*A);
	Animal	*C = new Animal();;
	*C = *A;

	delete C;
	delete B;
	delete A;
}

void	testB(void)
{
	std::cout << "======= TEST B ======" << std::endl;
	Cat	*A = new Cat();
	Cat	*B = new Cat(*A);
	Cat	*C = new Cat();
	*C = *A;

	delete C;
	delete B;
	delete A;
}

void	testC(void)
{
	std::cout << "======= TEST B ======" << std::endl;
	const Animal	*A = new Dog();
	const Animal	*B = new Cat();

	std::cout << A->getType() << std::endl;
	std::cout << B->getType() << std::endl;

	std::cout << " >  Dog's ideas      \n";
	A->getIdeas();
	std::cout << " >  Cat's ideas      \n";
	B->getIdeas();

	std::cout << " > Dog make sound      \n";
	A->makeSound();
	std::cout << " > Cat make sound      \n";
	B->makeSound();
	
	delete A;
	delete B;
}

int	main()
{
	atexit(a);

	testA();
	testB();
	testC();
	return (0);
}