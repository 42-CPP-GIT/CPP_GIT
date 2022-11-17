/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:31:45 by hchang            #+#    #+#             */
/*   Updated: 2022/11/17 17:47:21 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	private:
		std::string	_type;
	public:
		Ice();
		Ice(const Ice& obj);
		Ice& operator=(const Ice& obj);
		~Ice();
		Ice(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const;
		virtual void		use(ICharacter& target);
};

#endif
