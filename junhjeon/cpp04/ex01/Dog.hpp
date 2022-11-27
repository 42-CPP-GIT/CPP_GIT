/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:22:07 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/09 19:24:31 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _attribute;
	public:
		Dog();
		~Dog();
		Dog( const Dog& copy );
		Dog& operator = ( const Dog &d );
		virtual void	makeSound( void ) const;
		virtual Brain* getBrain( void ) const;
};

#endif
