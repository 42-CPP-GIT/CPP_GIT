/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:33:10 by jinypark          #+#    #+#             */
/*   Updated: 2023/01/02 14:18:43 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
	MutantStack<int> mstack;
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
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "----------------------------\n";
	{
		std::list<int> l;
		l.push_back(5);
		l.push_back(17);
		std::cout << l.back() << std::endl;
		l.pop_back();
		std::cout << l.size() << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		//[...]
		l.push_back(0);
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << "----------------------------\n";
		MutantStack<int, std::vector<int> > mstack;
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
		MutantStack<int, std::vector<int> >::MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
		// MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
		MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		// std::stack<int> s(mstack);
	}
	return (0);
}