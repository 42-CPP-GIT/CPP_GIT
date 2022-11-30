/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:58:36 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 09:17:17 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"
# define ON 1
# define OFF 0
class AMateria
{
protected:
	std::string		type_;
	unsigned int	isEquipped;
public:
	AMateria(std::string const & type);
	AMateria();
	virtual ~AMateria() {};
	AMateria(const AMateria &obj);
	AMateria&	operator=(const AMateria &obj);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	unsigned int	getIsEquipped() const;
	void			switchIsEquipped(int i);
};

#endif