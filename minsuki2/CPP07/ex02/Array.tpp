/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:10:16 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/22 21:17:32 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
	: arr_(new T[0]), size_(0) { }

template <typename T>
Array<T>::Array(unsigned int n)
	: arr_(new T[n]), size_(n) { }

template <typename T>
Array<T>::Array(const Array<T>& obj)
	: arr_(NULL) {
	*this = obj;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& obj) {
	if (this != &obj) {
		delete this->arr_;
		this->arr_ = new T[obj.size_];
		for (unsigned int i = 0; i < obj.size_; ++i) {
			this->arr_[i] = obj.arr_[i];
		}
		this->size_ = obj.size_;
	}
	return *this;
}

template <typename T>
Array<T>::~Array<T>(void) { 
	delete[] this->arr_;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) {
	if (idx >= this->size_) {
		throw Array<T>::OutOfIndexException();
	}
	return this->arr_[idx];
}

// 기본 연산자 불러오기 방지
template <typename T>
const T& Array<T>::operator[](unsigned int idx) const {
	if (idx >= this->size_) {
		throw Array<T>::OutOfIndexException();
	}
	return this->arr_[idx];
}

template <typename T>
unsigned int Array<T>::size(void) const { return this->size_; }

template <typename T>
const char* Array<T>::OutOfIndexException::what() const throw() { return "Out of index"; }
