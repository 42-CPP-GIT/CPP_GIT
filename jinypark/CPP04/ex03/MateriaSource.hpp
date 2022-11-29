/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:59:05 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 11:53:39 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <sstream>
# define INVENTORY_CNT 100

class MateriaSource : public IMateriaSource
{
// private:
public:
	static AMateria*	inventory[INVENTORY_CNT];
	unsigned int		inventoryCnt;
	AMateria*			slots[4];
	unsigned int		slotCnt;
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &obj);
	MateriaSource&	operator=(const MateriaSource &obj);
	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif