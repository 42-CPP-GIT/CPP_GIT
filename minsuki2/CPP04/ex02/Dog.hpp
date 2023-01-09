/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:01:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/09 15:53:25 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# define MSG_DOG	"[Dog]"
# define DOG_SOUND	")< bowwwboowwww"

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	public:
		Dog(void);
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		~Dog(void);
		void	makeSound() const;
		Brain*	getBrain(void) const;
	private:
		Brain*		own_brain_;
};

#endif
