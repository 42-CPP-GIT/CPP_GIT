/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:52:54 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/16 15:12:35 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array
{
private:
	T* arr;
	unsigned int size_;
public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& obj);
	Array&	operator=(const Array<T>& obj);
	T&	operator[](int idx);
	unsigned int size();
	~Array();
};


// #include "Array.tpp"