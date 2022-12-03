/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:24:32 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/23 12:00:37 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <unistd.h>

Base	*	generate (void)
{
	srand((unsigned int)time(NULL));

	int num = rand();
	if (num % 3 == 0)
		return (static_cast<Base *> (new A));
	else if (num % 3 == 1)
		return (static_cast<Base *> (new B));
	else
		return (reinterpret_cast<Base *> (new C));
}

void	identify( Base* p )
{
	A* a = dynamic_cast<A*> (p);
	if (a)
	{
		std::cout << "I am A" << std::endl;
		return ;
	}
	B* b = dynamic_cast<B*> (p);
	if (b)
	{
		std::cout << "I am B" << std::endl;
		return ;
	}
	C* c = dynamic_cast<C*> (p);
	if (c)
	{
		std::cout << "I am C" << std::endl;
		return ;
	}
	std::cout << "who am i ? " << std::endl;
	return ;
}

void	identify( Base& p )
{
	try
	{
		A& a = dynamic_cast<A&> (p);
		(void) a;
		std::cout << "I am A" << std::endl;
		return ;
	}
	catch(std::bad_cast)
	{
		try
		{
			B& b = dynamic_cast<B&> (p);
			(void) b;
			std::cout << "I am B" << std::endl;
			return ;
		}
		catch(std::bad_cast)
		{
			try
			{
				C& c = dynamic_cast<C&> (p);
				(void) c;
				std::cout << "I am C" << std::endl;
				return ;
			}
			catch(std::bad_cast)
			{
				;
			}
		}
	}
	std::cout << "who am i ? " << std::endl;
	return ;
}

int main ()
{
	Base *t;
	Base A;

	for (int i = 0; i < 10; i ++)
	{
		t = generate();
		identify(t);
		identify(*t);
		delete t;
		usleep(400000);
	}
	identify(A);
	identify(&A);
	identify(NULL);
}
