/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:36:55 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/06 22:39:59 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t*	ret = reinterpret_cast<uintptr_t *>(ptr);

	return (*ret);
}

Data* deserialize(uintptr_t raw)
{
	Data*	ret = reinterpret_cast<Data *>(&raw);

	return (ret);
}