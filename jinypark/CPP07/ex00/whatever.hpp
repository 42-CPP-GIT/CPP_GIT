/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:45:37 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/20 20:45:53 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b) { return (a < b ? a : b); }

template <typename T>
T max(T a, T b) { return (a > b ? a : b); }

#endif