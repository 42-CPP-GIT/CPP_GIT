/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:59:43 by sesim             #+#    #+#             */
/*   Updated: 2022/12/09 08:26:00 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void	a()
{
	system("leaks Animal");
}

int	main()
{
	// atexit(a);

	// const Animal	Test;
	const Animal	*A = new Dog();
	const Animal	*B = new Cat();

	A->makeSound();
	B->makeSound();

	std::cout << "=========\n";
	Dog	h1;
	{
		Dog test = h1;
	}


	delete A;
	delete B;
	return (0);
}