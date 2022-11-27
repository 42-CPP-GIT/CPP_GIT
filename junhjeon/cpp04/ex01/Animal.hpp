/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:25:40 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/09 19:12:09 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream> 
# include "Brain.hpp"

class Animal
{
	protected :
		std::string _type;
	public :
		Animal();
		Animal( std::string type );
		virtual ~Animal();
		Animal( const Animal& copy );
		Animal& operator = ( const Animal& a );
		virtual void makeSound( void ) const;
		virtual Brain* getBrain( void ) const;
		std::string getType( void ) const;
		void	setType( std::string name );
};

#endif
