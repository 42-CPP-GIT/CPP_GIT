/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:23:28 by jinypark          #+#    #+#             */
/*   Updated: 2023/01/02 08:54:11 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator	easyfind(T& container, int n)
{
	typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (std::exception());
	return (it);
}

template <typename T>
typename std::map<int, T>::iterator	easyfind(std::map<int, T>& container, int n)
{
	typename std::map<int, T>::iterator it;
	
	it = container.find(n);
	if (it == container.end())
		throw (std::exception());
	return (it);
}

template <typename T>
typename std::multimap<int, T>::iterator	easyfind(std::multimap<int, T>& container, int n)
{
	typename std::multimap<int, T>::iterator it;
	
	it = container.find(n);
	if (it == container.end())
		throw (std::exception());
	return (it);
}