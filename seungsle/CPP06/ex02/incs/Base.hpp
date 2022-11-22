/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:25:22 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 23:50:44 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H
#include <random>
#include <iostream>

class Base
{
private:
	/* data */
public:
	Base(/* args */);
	virtual ~Base();

	Base * generate(void);

	bool isAP(Base* object);
	bool isBP(Base* object);
	bool isCP(Base* object);

	bool isAR(Base& object);
	bool isBR(Base& object);
	bool isCR(Base& object);

	void identify(Base* p);
	void identify(Base& p);
};

#endif