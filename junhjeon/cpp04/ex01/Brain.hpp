/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:32:20 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/18 17:16:39 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	protected :
		std::string _ideas[100];
	public :
		Brain();
		virtual ~Brain();
		Brain( const Brain& copy);
		Brain& operator = ( const Brain& b );
		std::string* getIdeas ( void );
};

#endif
