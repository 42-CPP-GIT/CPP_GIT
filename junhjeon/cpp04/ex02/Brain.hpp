/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:32:20 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/21 16:31:56 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	private :
		std::string _ideas[100];
	public :
		Brain();
		~Brain();
		Brain( const Brain& copy);
		Brain& operator = ( const Brain& b );
		std::string* getIdeas ( void );
};

#endif
