/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:43:53 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/21 16:47:06 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
void a()
{
	system("leaks a.out");
}
int main()
{
	//const Animal a("hello"); abstract class 이기 때문에 instance 생성 불가능.
	/*const Animal* d = new Dog();
	const Animal* c = new Cat();
	Dog dog1;

	dog1.getBrain()->getIdeas()[0] = "i am dog1...?";
	d->getBrain()->getIdeas()[0] = "i am dog...?";
	c->getBrain()->getIdeas()[0] = "i am cat...?";

	Dog d2 = dog1;
	std::cout << " Before Change Ideas" << std::endl;
	std::cout << "dog1 : " << dog1.getBrain()->getIdeas()[0] << std::endl;
	std::cout << "dog2 : " << d2.getBrain()->getIdeas()[0] << std::endl;
	std::cout << std::endl;

	d2.getBrain()->getIdeas()[0] = "yes i am dog2 !";
	
	std::cout << " After Change Ideas" << std::endl;
	std::cout << "dog 1 : " << dog1.getBrain()->getIdeas()[0] << std::endl;
	std::cout << "dog 2 : " << d2.getBrain()->getIdeas()[0] << std::endl;
	std::cout << std::endl;
	*/
	//atexit(a);
	Animal *a[2];

	int i = 0;
	for (; i < 1; i++)
		a[i] = new Dog();
	for (; i < 2; i++)
		a[i] = new Cat();

	for (int j = 0; j < 2; j++)
		delete a[j];

	Cat *A = new Cat();
	Cat *B = new Cat(*A);
	Cat *C = new Cat();
	*C = *A;

	delete A;
	delete B;
	delete C;
	


	/*delete d;//should not create a leak
	delete c;
	*/

	return 0;
}
