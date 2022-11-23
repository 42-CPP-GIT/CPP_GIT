/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:25:56 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 23:57:20 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate()
{
	std::srand(time(NULL));
	int random = std::rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else if (random == 2)
		return new C();
	return NULL;
}

bool isAP(Base* object)
{
	A* a = dynamic_cast<A*>(object);
	if (a == NULL)
		return false;
	return true;
}

bool isBP(Base* object)
{
	B* b = dynamic_cast<B*>(object);
	if (b == NULL)
		return false;
	return true;
}

bool isCP(Base* object)
{
	C* c = dynamic_cast<C*>(object);
	if (c == NULL)
		return false;
	return true;
}

bool isAR(Base& object)
{
	try
	{
		A& a = dynamic_cast<A&>(object);
		(void)a;
	}
	catch(std::bad_cast exp)
	{
		return false;
	}
	return true;
}

bool isBR(Base& object)
{
	try
	{
		B& b = dynamic_cast<B&>(object);
		(void)b;
	}
	catch(std::bad_cast exp)
	{
		return false;
	}
	return true;
}

bool isCR(Base& object)
{
	try
	{
		C& c = dynamic_cast<C&>(object);
		(void)c;
	}
	catch(std::bad_cast exp)
	{
		return false;
	}
	return true;
}

void identify(Base* p)
{
	if (isAP(p))
		std::cout << "this is A" << std::endl;
	else if (isBP(p))
		std::cout << "this is B" << std::endl;
	else if (isCP(p))
		std::cout << "this is C" << std::endl;
	else
		std::cout << "i can't define myself" << std::endl;
}

void identify(Base& p)
{
	if (isAR(p))
		std::cout << "this is A" << std::endl;
	else if (isBR(p))
		std::cout << "this is B" << std::endl;
	else if (isCR(p))
		std::cout << "this is C" << std::endl;
	else
		std::cout << "i can't define myself" << std::endl;
}

int main()
{
	Base *a;

	a = generate();
	identify(*a);
	identify(a);
}