/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:45:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/25 22:18:59 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <exception>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		MutantStack(void) : std::stack<T>() { };
		MutantStack(const MutantStack& obj) : std::stack<T>(obj) { };
		MutantStack&	operator=(const MutantStack& obj) {
			return  this == &obj ? *this : std::stack<T>::operator=(obj);
		};
		~MutantStack(void) { };

		iterator			begin(void) { return std::stack<T>::c.begin(); }
		iterator			end(void) { return std::stack<T>::c.end(); }
		reverse_iterator	rbegin(void) { return std::stack<T>::c.rbegin(); }
		reverse_iterator	rend(void) { return std::stack<T>::c.rend(); }
		iterator			begin(void) const { return std::stack<T>::c.begin(); }
		iterator			end(void) const { return std::stack<T>::c.end(); }
		reverse_iterator	rbegin(void) const { return std::stack<T>::c.rbegin(); }
		reverse_iterator	rend(void) const { return std::stack<T>::c.rend(); }


		/* 에러가 나게 하는 방법도 좋다고 생각 */

		class MutantStackIsEmptyException : public std::exception {
			const char*		what(void) const throw() {
				return "The process is denied Because MutantStack is empty";
			};
		};

		T&					top(void) {
			return this->c.empty()
					? throw MutantStack::MutantStackIsEmptyException() : std::stack<T>::top();
		};

		T&					top(void) const {
			return this->c.empty()
					? throw MutantStack::MutantStackIsEmptyException() : std::stack<T>::top();
		};

		void				pop(void) {
			return this->c.empty()
					? throw MutantStack::MutantStackIsEmptyException() : std::stack<T>::pop();
		};
};

# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#endif
