/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:33:38 by jinypark          #+#    #+#             */
/*   Updated: 2023/01/03 18:50:23 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	~MutantStack();
	typedef typename Container::iterator iterator;
	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
private:
	MutantStack(const MutantStack& obj);
	MutantStack& operator=(const MutantStack& obj);
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& obj)
{
	*this = obj;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& obj)
{
	this->c = obj.c;
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

#endif