/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:22:39 by sesim             #+#    #+#             */
/*   Updated: 2022/12/20 08:54:51 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>

template <typename T>
class Array
{
	private:
		T				*arr_;
		unsigned int	size_;
	public:
		class OutOfBoundsException : public std::exception
		{
			public:
				const char*	what() const throw()
				{
					return ("err: index is out of range");
				}
		};
		Array<T>(void) : size_(0)
		{
			this->arr_ = new T[size_];
		}
		Array<T>(unsigned int n) : size_(n)
		{
			this->arr_ = new T[size_];
		}
		Array<T>(const Array<T>& obj)
		{
			this->arr_ = NULL;
			*this = obj;
		}
		Array<T>&	operator=(const Array<T>& obj)
		{
			if (this == &obj)
				return (*this);
			if (this->arr_)
				delete [] this->arr_;
			this->arr_ = new T[obj.size()];
			for (unsigned int i = 0; i < obj.size(); ++i)
				this->arr_[i] = obj.arr_[i];
			this->size_ = obj.size();
			return (*this);
		}
		T&	operator[](size_t index)
		{
			if (index < 0 || static_cast<unsigned int>(index) >= size_)
				throw OutOfBoundsException();
			return (this->arr_[index]);
		}
		unsigned int	size() const
		{
			return (this->size_);
		}
		~Array<T>()
		{
			if (this->arr_)
				delete [] this->arr_;
		}
};

