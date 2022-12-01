/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:47:04 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/24 13:26:14 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTAN_STACK_HPP
# define MUTAN_STACK_HPP

#include<iostream>
#include<stack>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	// typedef typename std::stack<T>::iterator iterator;
	MutantStack(/* args */): std::stack<T>()
	{
		
	};
	~MutantStack()
	{
		
	};
	MutantStack(const MutantStack &source): std::stack<T>(source)
	{

	};
	MutantStack& operator=(const MutantStack &source)
	{
		if (this == &source)
			return (*this);
		std::stack<T>::operator=(source);
		return (*this);
	};
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return (std::stack<T>::c.begin());
	}
	iterator end()
	{
		return (std::stack<T>::c.end());
	}
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const
	{
		return (std::stack<T>::c.begin());
	}
	const_iterator end() const 
	{
		return (std::stack<T>::c.end());
	}
};

#endif