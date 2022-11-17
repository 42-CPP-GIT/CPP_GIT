/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:51:10 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 23:51:53 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat(/* args */);
	Cat(std::string name);
	Cat(const Cat &cat);
	~Cat();
	Cat& operator = (const Cat &source);

	void makeSound(void) const;
	
	void grooming(void);
	void eatFish(void);
	void hunt(void);
};


#endif