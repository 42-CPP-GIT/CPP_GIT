/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:25:40 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/18 16:59:15 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream> 

class WrongAnimal
{
	protected :
		std::string _type;
	public :
		WrongAnimal();
		WrongAnimal( std::string type );
		virtual ~WrongAnimal();
		WrongAnimal( const WrongAnimal& copy );
		WrongAnimal& operator = ( const WrongAnimal& a );
		void makeSound( void ) const;
		std::string getType( void ) const;
};

#endif
