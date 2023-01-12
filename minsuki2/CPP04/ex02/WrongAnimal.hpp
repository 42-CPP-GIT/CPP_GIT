/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/06 16:25:05 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# define MSG_WRONGANIMAL			"[WrongAnimal]"
# define MSG_D_CONSTRUCT			"Default Constructor"
# define MSG_C_CONSTRUCT			"Copy Constructor"
# define MSG_C_A_OPERATE			"Copy assignment operator"
# define MSG_DESTRCUT				"Destructor"
# define WRONGANIMAL_SOUND			")< halb, halb, halb"

# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal&	operator=(const WrongAnimal& obj);
		~WrongAnimal(void);
		void				makeSound(void) const;
		const std::string&	getType(void) const;
	protected:
		std::string type;
};

#endif

