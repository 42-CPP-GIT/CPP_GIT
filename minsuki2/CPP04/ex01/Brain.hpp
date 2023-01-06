/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:42:11 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/06 19:39:41 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# define MSG_BRAIN				"[Brain]"
# define MSG_D_CONSTRUCT		"Default Constructor"
# define MSG_C_CONSTRUCT		"Copy Constructor"
# define MSG_C_A_OPERATE		"Copy assignment operator"
# define MSG_DESTRCUT			"Destructor"
# define ANIMAL_SOUND			")< blah, blah, blah"

# include <iostream>

class Brain {
	public:
		Brain(void);
		Brain(const Brain& obj);
		Brain&	operator=(const Brain& obj);
		~Brain(void);
		const std::string&	getIdea(int index) const;
		void				setIdea(int index, const std::string& idea);
	private:
		static const int	n_ideas_ = 100;
		std::string			ideas_[n_ideas_];
};

#endif
