/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:47 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/23 18:39:04 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# define MSG_ANIMAL				"[Animal]"
# define MSG_D_CONSTRUCT		"Default Constructor"
# define MSG_C_CONSTRUCT		"Copy Constructor"
# define MSG_C_A_OPERATE		"Copy assignment operator"
# define MSG_DESTRCUT			"Destructor"
# define ANIMAL_SOUND			")< blah, blah, blah"

# include <iostream>

class Animal {
	public:
		Animal(void);
		Animal(const Animal& obj);
		Animal&	operator=(const Animal& obj);
		~Animal(void);
		virtual void		makeSound() const;
		const std::string&	getType(void) const;
	protected:
		std::string type;
};

#endif

