/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:34:15 by hchang            #+#    #+#             */
/*   Updated: 2022/11/30 19:49:21 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand(time(NULL));
	int rand_var = rand();

	if (rand_var % 3 == 0)
		return (new A());
	else if (rand_var % 3 == 1)
		return (new B());
	else
		return (new C());
	return NULL;
}

bool	isAPtr(Base *obj)
{
	A* a = dynamic_cast<A*>(obj);
	if (!a)
		return (false);
	return (true);
}

bool	isBPtr(Base *obj)
{
	B* b = dynamic_cast<B*>(obj);
	if (!b)
		return (false);
	return (true);
}

bool	isCPtr(Base *obj)
{
	C* c = dynamic_cast<C*>(obj);
	if (!c)
		return (false);
	return (true);
}

void identify(Base* p)
{
	if (isAPtr(p))
		std::cout << GRN << "YES! THIS IS A PTR" << RESET << std::endl;
	else if (isBPtr(p))
		std::cout << GRN << "YES! THIS IS B PTR" << RESET << std::endl;
	else if (isCPtr(p))
		std::cout << GRN << "YES! THIS IS C PTR" << RESET << std::endl;
	else
		std::cout << RED << "NO! THIS IS UNKNOWN PTR" << RESET << std::endl;
}

bool	isARef(Base &obj)
{
	try
	{
		A& a = dynamic_cast<A&>(obj);
		(void)a;
	}
	catch(std::bad_cast &e)
	{
		return (false);
	}
	return (true);
}

bool	isBRef(Base &obj)
{
	try
	{
		B& b = dynamic_cast<B&>(obj);
		(void)b;
	}
	catch(std::bad_cast &e)
	{
		return (false);
	}
	return (true);
}

bool	isCRef(Base &obj)
{
	try
	{
		C& c = dynamic_cast<C&>(obj);
		(void)c;
	}
	catch(std::bad_cast &e)
	{
		return (false);
	}
	return (true);
}

void identify(Base& p)
{
	if (isARef(p))
	{
		std::cout << GRN << "YES! THIS IS A Ref" << RESET << std::endl;
		return ;
	}
	else if (isBRef(p))
	{
		std::cout << GRN << "YES! THIS IS B Ref" << RESET << std::endl;
		return ;
	}
	else if (isCRef(p))
	{
		std::cout << GRN << "YES! THIS IS C Ref" << RESET << std::endl;
		return ;
	}
	else
		std::cout << RED << "NO! THIS IS UNKNOWN Ref" << RESET << std::endl;
	return ;
}


void	allExampleCheck()
{
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();
	Base *base = new Base();

	identify(a);
	identify(b);
	identify(c);
	identify(base);

	Base &a1 = *a;
	Base &b1 = *b;
	Base &c1 = *c;
	Base &base1 = *base;

	identify(a1);
	identify(b1);
	identify(c1);
	identify(base1);

	delete a;
	delete b;
	delete c;
	delete base;
}

void subject()
{
	Base *test = generate();
	identify(test);
	
	Base &test1 = *test;
	identify(test1);
	delete test;
}

int main(void)
{
	// allExampleCheck();
	subject();
}
