/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:55:53 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 15:17:59 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "MateriaSource.hpp"

class Character : public ICharacter
{
private:
	std::string name_;
	AMateria*	slots[SLOT_CNT];
public:
	Character();
	Character(const std::string type);
	~Character();
	Character(const Character &obj);
	Character&	operator=(Character const &obj);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria* getFirstMateria() const;
};

#endif