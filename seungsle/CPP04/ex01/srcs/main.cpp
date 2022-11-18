/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:51:28 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/18 11:26:58 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Rabit.hpp"

int main()
{
	Animal *a[100];

	int i = 0;
	int j = 0;
	for (; i < 50; i++)
		a[i] = new Dog();
	for (; i < 100; i++)
		a[i] = new Cat();

	for (; j < 100; j++)
		delete a[j];

	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// while (1)
	// 	;
	// delete i;
	return 0;
}