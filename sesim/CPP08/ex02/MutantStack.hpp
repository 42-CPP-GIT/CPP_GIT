/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:51:01 by sesim             #+#    #+#             */
/*   Updated: 2022/12/02 13:09:01 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <exception>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		class EmptyStackException : public std::exception
		{
			const char* what() const throw()
			{
				return ("Stack is empty");
			}
		};
		MutantStack() {}
		MutantStack(const MutantStack& obj)
		{
			*this = obj;
		}
		MutantStack& operator=(const MutantStack& obj)
		{
			this->c = obj.c;
		}
		~MutantStack() {}
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		T& top(void)
		{
			if (this->c.empty())
				throw EmptyStackException();
			return (std::stack<T>::c.back());
		}
		const T& top(void) const
		{
			if (this->c.empty())
				throw EmptyStackException();
			return (std::stack<T>::c.back());
		}
		void	pop(void)
		{
			if (this->c.empty())
				throw EmptyStackException();
			this->c.pop_back();
		}
		iterator	begin()
		{
			return iterator(this->c.begin());
		}
		iterator	end()
		{
			return iterator(this->c.end());
		}
		const iterator	begin() const
		{
			return iterator(this->c.cbegin());
		}
		const iterator	end() const
		{
			return iterator(this->c.cend());
		}
};

#endif
