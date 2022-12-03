/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:52:24 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 15:16:09 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type_;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& obj);
		AMateria& operator=(const AMateria & obj);
		std::string const&	getType() const;
		virtual	AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
		virtual	~AMateria();
};

#endif
