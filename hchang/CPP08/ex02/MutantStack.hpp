/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:33:28 by hchang            #+#    #+#             */
/*   Updated: 2022/12/02 12:31:49 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <exception>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		class	OutofBoundException : public std::exception
		{
			public :
				const char * what() const throw()
				{
					return ("ERROR : You Access Out of Bounds");
				}
		};
		class	EmptyException : public std::exception
		{
			public :
				const char * what() const throw()
				{
					return ("ERROR : Your Stack is Empty");
				}
		};
		MutantStack()
		: std::stack<T>() 
		{
			std::cout << "default constructor\n";
		}
		MutantStack(const MutantStack<T>& obj) 
		: std::stack<T>()
		{
			std::cout << "copy constructor\n";
			*this = obj;
		}
		MutantStack<T>& operator=(const MutantStack<T>& obj)
		{
			if (this == &obj)
				return (*this);	
			std::stack<T>::c = obj.std::stack<T>::c;
			return (*this);
		}
		~MutantStack(){};
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		iterator begin()
		{
			if (std::stack<T>::c.empty())
				throw EmptyException();
			return std::stack<T>::c.begin();
		}
		iterator end()
		{
			if (std::stack<T>::c.empty())
				throw EmptyException();
			return std::stack<T>::c.end();
		}
		const_iterator begin( void ) const
		{
			if (std::stack<T>::c.empty())
				throw EmptyException();
			return std::stack<T>::c.cbegin();
		}
		const_iterator end( void ) const
		{
			if (std::stack<T>::c.empty())
				throw EmptyException();
			return std::stack<T>::c.cend();
		}
		T&	top(void)
		{
			if (std::stack<T>::c.empty())
				throw EmptyException();
			return (std::stack<T>::c.back());
		}
		const T&	top(void) const
		{
			if (std::stack<T>::c.empty())
				throw EmptyException();
			return (std::stack<T>::c.back());
		}
		void	pop(void)
		{
			if (std::stack<T>::c.empty())
				throw EmptyException();
			std::stack<T>::c.pop_back();
		}
};

#endif
