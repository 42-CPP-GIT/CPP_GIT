/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:21:06 by sesim             #+#    #+#             */
/*   Updated: 2022/11/28 16:48:26 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "Animal.hpp"

class WrongCat : public Animal
{
	private:
		std::string	name_;

public:
	WrongCat();
	WrongCat(const WrongCat& obj);
	WrongCat& operator=(const WrongCat& obj);
	void				makeSound(void) const;
	const std::string&	getName(void) const;
	~WrongCat();
};

#endif
