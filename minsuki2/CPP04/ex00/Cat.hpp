/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:59:45 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/23 18:22:32 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>

# include "Animal.hpp"
# define MSG_CAT	"[Cat]"
# define CAT_SOUND	")< meow~ meow~!"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
		~Cat(void);
		void	makeSound() const;
};

#endif
