/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:51:10 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/18 16:19:41 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
	/* data */
public:
	WrongCat(/* args */);
	WrongCat(std::string name);
	WrongCat(const WrongCat &WrongCat);
	~WrongCat();
	WrongCat& operator = (const WrongCat &source);

	void makeSound(void) const;
};

#endif