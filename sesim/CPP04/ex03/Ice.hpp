/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:49:03 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 20:24:11 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string const & type);
		Ice(const Ice& obj);
		Ice& operator=(const Ice& obj);
		std::string const &	getType() const;
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
		virtual ~Ice();
};

#endif
