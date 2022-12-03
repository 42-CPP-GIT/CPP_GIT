/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:00:43 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 22:18:32 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void a()
{
	system("leaks a.out");
}

void	test1(void)
{
	std::cout << "====== test 1 ======\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// src->learnMateria(new Ice());
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	
	Character* me = new Character("me");
	
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	// std::cout << tmp->getType() << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	AMateria* tmp1;
	tmp1 = tmp->clone(); // tmp1을 할당해제를 어떤식으로 처리해야 될지?

	me->equip(tmp1);
	me->equip(tmp1);
	me->equip(tmp1);
	me->equip(tmp1);
	me->unequip(0);

	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("whatthe");
	// me->equip(tmp);

	Character* bob = new Character("sesim");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	// me->use(3, *bob);
	// me->use(1, *bob);
	// me->use(2, *me);

	// me->use(6, *bob);
	
	delete bob;
	delete me;
	std::cout << "      aa      \n";
	delete src;
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
	atexit(a);
	subject();
	MateriaSourceAssignmentOperator();
	CharacterAssignmentOperator();
	BothAssignmentOperator();
	test1();

	MateriaSource::clearFloor();
	return 0;
}