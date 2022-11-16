/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:31:45 by hchang            #+#    #+#             */
/*   Updated: 2022/11/16 17:55:14 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	private:
		std::string	_type;
	public:
		Cure(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
