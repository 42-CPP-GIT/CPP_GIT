/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:30:52 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/01 18:24:42 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
	private :
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	public :
		void	(Harl::*comp[4])(void);
		void	complain( std::string level );
		Harl();
};

#endif
