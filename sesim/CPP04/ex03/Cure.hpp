/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:49:03 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 20:24:19 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string const & type);
		Cure(const Cure& obj);
		Cure& operator=(const Cure& obj);
		std::string const &	getType() const;
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
		virtual ~Cure();
};

#endif
