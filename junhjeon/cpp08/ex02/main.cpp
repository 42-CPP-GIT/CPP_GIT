/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:06:33 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/25 21:39:19 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <stack>

int main()
{
	try{
	MutantStack<int> mstack;
	//mstack.pop();
	//mstack.top();
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	
	//MutantStack<int>::iterator it;

	std::stack<int> s(mstack);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;

	std::cout << " -------------------------------- " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << " -------------------------------- " << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}

	return 0;
}
