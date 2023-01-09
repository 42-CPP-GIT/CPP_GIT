/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:59:45 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/09 15:53:11 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# define MSG_CAT	"[Cat]"
# define CAT_SOUND	")< meow~ meow~!"

class Cat : public AAnimal {
	public:
		Cat(void);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
		~Cat(void);
		void				makeSound(void) const;
		Brain*				getBrain(void) const;
	private:
		Brain*		own_brain_;
};

#endif
