/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:06:11 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 14:33:57 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type_;

	public:
		Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		const std::string&		getType(void) const;
		virtual void			makeSound(void) const;
		virtual void			getIdeas(void) const;
		virtual					~Animal();
};

#endif
