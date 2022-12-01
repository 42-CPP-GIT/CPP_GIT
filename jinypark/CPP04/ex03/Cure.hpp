/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:51:34 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 02:47:29 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
public:
	Cure();
	virtual ~Cure();
	Cure(const Cure &obj);
	Cure&	operator=(const Cure &obj);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif