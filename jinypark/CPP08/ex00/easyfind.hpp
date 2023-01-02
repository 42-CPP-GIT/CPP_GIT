/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:11:17 by jinypark          #+#    #+#             */
/*   Updated: 2023/01/02 13:40:15 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <algorithm>
# include <map>
# include <iterator>

template <typename T>
typename T::iterator	easyfind(T& container, int n);

template <typename T>
typename std::map<int, T>::iterator	easyfind(std::map<int, T>& container, int n);

template <typename T>
typename std::multimap<int, T>::iterator	easyfind(std::multimap<int, T>& container, int n);

# include "easyfind.tpp"

#endif
