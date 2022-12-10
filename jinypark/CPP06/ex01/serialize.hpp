/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:41:45 by jinypark          #+#    #+#             */
/*   Updated: 2022/12/10 19:22:46 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

# include <iostream>
# include "Data.hpp"
# define ENDL "\n"

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif