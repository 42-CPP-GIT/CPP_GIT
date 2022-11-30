/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:32:47 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 12:01:31 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# define RESET "\033[0m"
# define IT "\e[0;3m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLE "\e[0;34m"

#include <iostream>
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string			_name;
		int					_slotIdx;
		AMateria			*_slot[4];

	public:
		static AMateria		*_floor[10];
		static int			_floorIdx;
		const AMateria* getAMateria(int idx) const;
		Character(std::string name);
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
