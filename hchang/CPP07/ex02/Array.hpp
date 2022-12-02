/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:18:43 by hchang            #+#    #+#             */
/*   Updated: 2022/12/02 11:59:15 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int	_len;
		T				*_array;

	public:
		class	OutofBoundException : public std::exception
		{
			public :
				const char * what() const throw()
				{
					return ("ERROR : You Access Out of Bounds");
				}
		};
		Array<T>() : _len(0)
		{
			_array = new T[0];
		}
		Array<T>(unsigned int n) : _len(n)
		{
			_array = new T[n];
		}
		Array<T>(const Array<T>& obj)
		{
			this->_array = 0;
			*this = obj;
		}
		Array<T>&	operator=(const Array<T>& obj)
		{
			if (this == &obj)
				return (*this);
			this->_len = obj._len;
			if (this->_array)
				delete [] this->_array;
			this->_array = new T[obj.size()];
			for (size_t i = 0; i < obj.size(); i++)
				this->_array[i] = obj[i];
			return (*this);
		}
		T&	operator[](unsigned int n) const
		{
			if (n >= this->_len)
				throw OutofBoundException();
			return (this->_array[n]);
		}
		unsigned int	size(void) const
		{
			return (this->_len);
		}
		~Array<T>()
		{
			std::cout << "bye\n";
			if (this->_array)
				delete [] _array;
		}
};

#endif
