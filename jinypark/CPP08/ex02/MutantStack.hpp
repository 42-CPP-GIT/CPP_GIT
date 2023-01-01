/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:33:38 by jinypark          #+#    #+#             */
/*   Updated: 2023/01/01 23:21:26 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }

	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;

	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;

	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}
