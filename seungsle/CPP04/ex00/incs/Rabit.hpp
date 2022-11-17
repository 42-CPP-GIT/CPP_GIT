/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rabit.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:51:10 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 18:19:32 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RABIT_HPP
# define RABIT_HPP

#include "WrongAnimal.hpp"

class Rabit: public WrongAnimal
{
private:
	/* data */
public:
	Rabit(/* args */);
	Rabit(std::string name);
	Rabit(const Rabit &Rabit);
	~Rabit();
	Rabit& operator = (const Rabit &source);
};

#endif