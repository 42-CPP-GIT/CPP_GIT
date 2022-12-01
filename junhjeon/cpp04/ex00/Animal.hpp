/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:25:40 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/18 16:59:02 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream> 

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
		std::string getType( void ) const;
};

#endif
