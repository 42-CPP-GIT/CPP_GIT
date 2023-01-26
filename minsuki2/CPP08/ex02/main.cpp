/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:52:01 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/27 02:54:54 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

template <typename T>
static	void	_showContainer(T& target) {
	std::cout << YELLOW << "(begin) " << RESET << " ➜ ";
	for (typename T::const_iterator it = target.begin()
		; it != target.end(); ++it) {
		std::cout << *it << " ➜ ";
	}
	std::cout << YELLOW << "(end)" << RESET << std::endl;
}

template <typename T>
static	void	_showContainerReverse(T& target) {
	std::cout << YELLOW << "(rbegin)" << RESET << " ➜ ";
	for (typename T::const_reverse_iterator it(target.rbegin())
		; it != target.rend(); ++it) {
		std::cout << *it << " ➜ ";
	}
	std::cout << YELLOW << "(rend)" << RESET << std::endl;
}

int main()
{

	std::cout << BOLDBLUE << "[CASE 1] : MutantStack" << std::endl
			  << "------------------------" << RESET << std::endl;
	try {
        MutantStack<int> ms;
		// ms.pop();					// <- seg.fault 방지
		// ms.top();					// <- seg.fault 방지
        ms.push(5);
        ms.push(17);
		_showContainer(ms);
        std::cout << "MutantStack top  : " << ms.top() << std::endl;
        ms.pop();
        std::cout << "MutantStack size : " << ms.size() << std::endl;
        ms.push(3); ms.push(5); ms.push(737); ms.push(0);
		_showContainer(ms);
		_showContainerReverse(ms);

		std::cout << BOLDMAGENTA << " --- Copy constructor --- " << RESET << std::endl;
        MutantStack<int> ms1(ms);
		_showContainer(ms1);
		std::cout << BOLDMAGENTA << " --- Copy assign operator --- " << RESET << std::endl;
        MutantStack<int> ms2 = ms1;
		_showContainer(ms2);

		std::stack<int> s(ms);
    } catch (std::exception& e) {
		std::cout << "[Error] " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << BOLDBLUE << "[CASE 2] : [+]list (just compare)" << std::endl
			  << "----------------------------------" << RESET << std::endl;
    {
        std::list<int> list;
        list.push_front(5);
        list.push_front(17);
        std::cout << "list front  : " << list.front() << std::endl;
		_showContainer(list);
        list.pop_front();
		_showContainer(list);
        std::cout << "list size : " << list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
		_showContainer(list);
        list.pop_back();
		_showContainer(list);
        list.push_back(0);
		_showContainer(list);
		_showContainerReverse(list);

        std::list<int> s(list);
    }
    return 0;
}
