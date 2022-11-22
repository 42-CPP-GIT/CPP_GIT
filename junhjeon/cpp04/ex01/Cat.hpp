/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:32:01 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/09 19:26:34 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _attribute;
	public:
		Cat();
		~Cat();
		Cat( const Cat& copy );
		Cat& operator = ( const Cat &d );
		virtual void	makeSound( void ) const;
		virtual Brain*	getBrain( void ) const;
};

#endif
