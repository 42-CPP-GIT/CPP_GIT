/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:52:54 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/20 22:09:29 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

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
	unsigned int size() const;
	~Array();
	class	ErrorOutOfIndex : public std::exception
	{
		const char* what() const throw();
	};
};

# include "Array.tpp"

#endif