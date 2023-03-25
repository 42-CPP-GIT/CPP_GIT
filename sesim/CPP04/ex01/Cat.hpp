/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:21:06 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 14:27:16 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		std::string	name_;
		Brain		*brain_;

	public:
		Cat();
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
		void				makeSound(void) const;
		void				getIdeas(void) const;
		const std::string&	getName(void) const;
		~Cat();
};

#endif