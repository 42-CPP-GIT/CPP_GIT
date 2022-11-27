/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:32:01 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/19 20:03:17 by junhjeon         ###   ########.fr       */
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
		virtual ~Cat();
		Cat( const Cat& copy );
		Cat& operator = ( const Cat &d );
		virtual void	makeSound( void ) const;
		virtual Brain*	getBrain( void ) const;
};

#endif
