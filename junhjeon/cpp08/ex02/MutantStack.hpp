/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:07:39 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/25 21:38:38 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>
#include <string>

template <typename T>
class MutantStack : public std::stack<T>
{
	protected :
		;
	public :
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack<T>& copy);
		MutantStack<T>& operator = ( const MutantStack<T>& m);
		T&	top( void )
		{
			if ( std::stack<T>::c.empty() )
				throw MutantException();
			else
				return (std::stack<T>::c.back());
		}
		const T& top( void ) const
		{
			if ( std::stack<T>::c.empty())
				throw MutantException();
			else
				return (std::stack<T>::c.back());
		}
		void pop( void )
		{
			if (std::stack<T>::c.empty())
				throw MutantException();
			else
				std::stack<T>::c.pop_back();
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator begin( void )
		{
			return std::stack<T>::c.begin();
		}
		iterator end( void )
		{
			return std::stack<T>::c.end();
		}
		const_iterator begin( void ) const
		{
			return std::stack<T>::c.begin();
		}
		const_iterator end( void ) const
		{
			return std::stack<T>::c.end();
		}
	public :
	class MutantException : public std::exception
	{
		public:
			const char * what() const throw();
	};
};


template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "constructor" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Destructor" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & copy) : std::stack<T>()
{
	std::cout << "copy constr" << std::endl;
	*this = copy;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator = ( const MutantStack<T>& m)
{
	if (*this != &m)
	{
		std::stack<T>::c = m.std::stack<T>::c;
	}
	return (*this);
}

template <typename T>
const char * MutantStack<T>::MutantException::what() const throw()
{
	return "Mutant stack is empty\n";
}
