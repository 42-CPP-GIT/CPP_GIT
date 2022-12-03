/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:20:01 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 17:08:37 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "MateriaSource.hpp"

class Character : public ICharacter
{
	private:
		AMateria	*slot_[4];
		std::string	name_;
		int			idx_;

	public:
		Character(std::string name);
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		const AMateria				*getAMateria(int idx) const;
		virtual std::string const&	getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
		virtual ~Character();
};

#endif
