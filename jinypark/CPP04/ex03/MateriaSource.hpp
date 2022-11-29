/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:59:05 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 16:04:06 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <sstream>
# define INVENTORY_CNT 100
# define SLOT_CNT 4

class MateriaSource : public IMateriaSource
{
private:
	static AMateria*	inventory[INVENTORY_CNT];
	AMateria*			slots[SLOT_CNT];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &obj);
	MateriaSource&	operator=(const MateriaSource &obj);
	void 		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const & type);
	static bool	removeFromInven(AMateria* m);
	static bool	putInInven(AMateria* m);
	void		printSlot(std::string name);
};

#endif