/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/09 15:52:26 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# define MSG_ANIMAL				"[AAnimal]"
# define MSG_D_CONSTRUCT		"Default Constructor"
# define MSG_C_CONSTRUCT		"Copy Constructor"
# define MSG_C_A_OPERATE		"Copy assignment operator"
# define MSG_DESTRCUT			"Destructor"
# define ANIMAL_SOUND			")< blah, blah, blah"

# include <iostream>

class AAnimal {
	public:
		AAnimal(void);
		AAnimal(const AAnimal& obj);
		AAnimal&	operator=(const AAnimal& obj);
		virtual				~AAnimal(void);
		virtual void		makeSound(void) const = 0;
		const std::string&	getType(void) const;
	protected:
		std::string type_;
};

#endif

