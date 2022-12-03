/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:09:15 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/25 14:35:11 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private :
		T*	_ary;
		unsigned int	_size;
	public :
		~Array( void );
		Array( void );
		Array( unsigned int n );
		Array( const Array<T>& copy);
		unsigned int	size ( void ) const;
		T* getAry ( void ) const;
		T& operator [] ( unsigned int idx ) const;
		Array<T>& operator = (const Array<T>& a);

		class MyError : public std::exception
		{
			public :
				const char* what() const throw();
		};
};

template <typename T>
Array<T>::~Array()
{
	if (!_ary)
		delete _ary;
}

template <typename T>
const char* Array<T>::MyError::what() const throw()
{
	return "wrong index";
}

template <typename T>
T*	Array<T>::getAry ( void ) const 
{
	return (_ary);
}

template <typename T>
Array<T>::Array( const Array<T>& copy)
{
	_ary = 0;
	_size = 0;
	*this = copy;
}

template <typename T>
Array<T>& Array<T>::operator = ( const Array<T>& a)
{
	if (this != &a)
	{
		T* temp = a.getAry();
		if (_ary)
			delete _ary;
		_ary = new T[a.size()];
		_size = a.size();
		for (unsigned int i = 0; i < _size; i ++)
			_ary[i] = temp[i];
	}
	return (*this);
}

template <typename T>
unsigned int	Array<T>::size( void ) const
{
	return (_size);
}

template <typename T>
T& Array<T>::operator [] ( unsigned int idx ) const
{
	if (idx >= _size)
	{
		throw MyError();
	}
	return (_ary[idx]);
}

template <typename T>
Array<T>::Array ( void )
{
	std::cout << "constructor " << std::endl;
	_ary = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array ( unsigned int n )
{

	_size = n;
	_ary = new T[n];
	//std::cout << "display : " <<  *_ary << std::endl;
	
}

