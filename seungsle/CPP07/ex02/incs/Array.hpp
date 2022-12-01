/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:38:46 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/24 11:27:53 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
private:
	T *_array;
	unsigned int _n;
public:
	class IndexOutOfBound: public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "index out of bound";
		};
	};
	Array():_n(0)
	{
		this->_array = new T[0];
	};
	Array(unsigned int n):_n(n)
	{ 
		this->_array = new T[n];
		for (unsigned int i = 0; i < n; i++)
		{
			this->_array[i] = 0;
		}
	};
	Array(const Array &source):_array(0), _n(0)
	{
		*this = source;
	};
	~Array()
	{
		delete[] this->_array;
	};
	Array& operator=(const Array &source)
	{ 
		if (this == &source)
			return (*this);
		if (this->_array)
			delete this->_array;
		this->_array = new T[source._n];
		this->_n = source._n;
		for (unsigned int i = 0; i < source._n; i++)
		{
			this->_array[i] = source._array[i];
		}
		return (*this);
	};
	T &operator[] (unsigned int index)
	{
		if (index >= this->_n)
			throw(Array::IndexOutOfBound());
		return (this->_array[index]);
	};
	int size(void) const
	{
		return (this->_n);
	};
};


#endif