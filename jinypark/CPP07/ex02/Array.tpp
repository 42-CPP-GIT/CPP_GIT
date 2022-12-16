/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:57:26 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/16 15:12:21 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
	std::cout << "default\n";
	this->arr = new T;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "size\n";
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
	(void)obj;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	(void)obj;
}

template <typename T>
T& Array<T>::operator[](int idx)
{
	std::cout << "[] in\n";
	std::cout << idx << "\n";
	return (this->arr[idx]);
}

template <typename T>
unsigned int Array<T>::size()
{
	return (this->size_);
}