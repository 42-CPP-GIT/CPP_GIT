/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:31:45 by hchang            #+#    #+#             */
/*   Updated: 2022/11/21 21:46:32 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define RESET "\033[0m"
# define IT "\e[0;3m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLE "\e[0;34m"

#include <iostream>
#include <iomanip>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string		_type;

	public:
		AMateria();
		virtual ~AMateria();
		AMateria(std::string const & type);
		std::string const &	getType() const; //Returns the materia type
		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);

};

#endif
