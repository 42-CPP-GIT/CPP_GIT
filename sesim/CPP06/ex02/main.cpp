/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:42:18 by sesim             #+#    #+#             */
/*   Updated: 2022/12/15 14:13:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generator(void)
{
	std::srand(time(NULL));
	int	rand_val(rand());

	if (rand_val % 3 == 0)
		return (new A());
	else if (rand_val % 3 == 1)
		return (new B());
	else
		return (new C());
}

bool	isAPtr(Base *obj)
{
	A*	tmp = dynamic_cast<A*>(obj);
	if (!tmp)
		return (false);
	return (true);
}

bool	isBPtr(Base *obj)
{
	B*	tmp = dynamic_cast<B*>(obj);
	if (!tmp)
		return (false);
	return (true);
}

bool	isCPtr(Base *obj)
{
	C*	tmp = dynamic_cast<C*>(obj);
	if (!tmp)
		return (false);
	return (true);
}

bool	isARef(Base& obj)
{
	try
	{
		A&	tmp(dynamic_cast<A&>(obj));
		(void)tmp;
	}
	catch(std::bad_cast& e)
	{
		return (false);
	}
	return (true);
}

bool	isBRef(Base& obj)
{
	try
	{
		B&	tmp(dynamic_cast<B&>(obj));
		(void)tmp;
	}
	catch(std::bad_cast& e)
	{
		return (false);
	}
	return (true);
}

bool	isCRef(Base& obj)
{
	try
	{
		C&	tmp(dynamic_cast<C&>(obj));
		(void)tmp;
	}
	catch(std::bad_cast& e)
	{
		return (false);
	}
	return (true);
}

void	identify(Base* obj)
{
	if (isAPtr(obj))
		std::cout << "This is A PTR!" << std::endl;
	else if (isBPtr(obj))
		std::cout << "This is B PTR!" << std::endl;
	else if (isCPtr(obj))
		std::cout << "This is C PTR!" << std::endl;
	else
		std::cout << "What the hell are you put in?" << std::endl;
}

void	identify(Base& obj)
{
	if (isARef(obj))
	{
		std::cout << "This is A REF!" << std::endl;
		return ;
	}
	else if (isBRef(obj))
	{
		std::cout << "This is B REF!" << std::endl;
		return ;
	}
	else if (isCRef(obj))
	{
		std::cout << "This is C REF!" << std::endl;
		return ;
	}
	else
		std::cout << "What the hell are you put in?" << std::endl;
}

int	main(void)
{
	Base*	ap(generator());
	Base*	bp(generator());
	Base*	cp(generator());
	Base*	base_ptr(generator());

	identify(ap);
	identify(bp);
	identify(cp);
	identify(base_ptr);

	Base&	ar(*ap);
	Base&	br(*bp);
	Base&	cr(*cp);
	Base&	base_ref(*base_ptr);

	identify(ar);
	identify(br);
	identify(cr);
	identify(base_ref);

	delete ap;
	delete bp;
	delete cp;
	delete base_ptr;
}
