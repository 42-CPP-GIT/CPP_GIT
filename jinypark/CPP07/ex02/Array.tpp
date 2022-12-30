/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:57:26 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/30 18:59:39 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
	this->arr = new T[0];
	this->size_ = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n];
	this->size_ = n;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->arr;
}

template <typename T>
Array<T>::Array(const Array<T>& obj)
{
	this->arr = NULL;
	*this = obj;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	delete[] this->arr;
	this->size_ = obj.size_;

	this->arr = new T[this->size_];
	for (unsigned int i = 0; i < this->size_; ++i)
	{
		this->arr[i] = obj.arr[i];
	}
	return (*this);
}

template <typename T>
const char* Array<T>::ErrorOutOfIndex::what() const throw()
{
	return ("Out of index!");
}

template <typename T>
T& Array<T>::operator[](int idx)
{
	if (idx < 0 || idx >= static_cast<int>(this->size_))
		throw (ErrorOutOfIndex());
	return (this->arr[idx]);
}

template <typename T>
const T& Array<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= static_cast<int>(this->size_))
		throw (ErrorOutOfIndex());
	return (this->arr[idx]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->size_);
}