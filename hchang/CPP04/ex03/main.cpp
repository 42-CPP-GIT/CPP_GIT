/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:11 by hchang            #+#    #+#             */
/*   Updated: 2022/11/25 15:02:03 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

AMateria	*Character::_floor[10] = {0,};
int			Character::_floorIdx = 0;

void a()
{
	system("leaks Materia");
}

void floorClear()
{
	for (int i = 0; i < Character::_floorIdx; i++)
	{
		if (Character::_floor[i])
			delete Character::_floor[i];
	}
}

void subject()
{
	AMateria* tmp;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	// tmp = src->createMateria("hi");
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	// me->use(4, *bob);

	delete bob;
	delete me;
	delete src;
}

void MateriaSourceAssignmentOperator()
{
	AMateria* tmp;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	MateriaSource* src = new MateriaSource();
	MateriaSource* src2 = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	*src2 = *src;

	tmp = src2->createMateria("ice");
	me->equip(tmp);
	tmp = src2->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	delete src2;
}

void	CharacterAssignmentOperator()
{
	AMateria* tmp;
	Character* me = new Character("me");
	Character* hchang = new Character("hchang");
	Character* bob = new Character("bob");
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	*hchang = *me;
	
	me->use(0, *bob);
	me->use(1, *bob);

	delete hchang;
	delete bob;
	delete me;
	delete src;
}

void	BothAssignmentOperator()
{
	AMateria* tmp;
	Character* me = new Character("me");
	Character* hchang = new Character("hchang");
	Character* bob = new Character("bob");
	MateriaSource* src = new MateriaSource();
	MateriaSource* src2 = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	*src2 = *src;
	
	tmp = src2->createMateria("ice");
	me->equip(tmp);
	tmp = src2->createMateria("cure");
	me->equip(tmp);

	*hchang = *me;

	hchang->use(0, *bob);
	hchang->use(1, *bob);

	delete me;
	delete bob;
	delete src;
	delete src2;
	delete hchang;
}


int main()
{
	// atexit(a);
	subject();
	// MateriaSourceAssignmentOperator();
	// CharacterAssignmentOperator();
	// BothAssignmentOperator();

	floorClear();
	return 0;
}