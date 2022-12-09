/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:00:43 by sesim             #+#    #+#             */
/*   Updated: 2022/12/09 09:11:34 by sesim            ###   ########.fr       */
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
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// me->unequip(0);
	// me->unequip(1);
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	Character* bob = new Character("sesim");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(1, *bob);
	me->use(2, *me);

	me->use(6, *bob);
	
	delete bob;
	delete me;
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
	tmp = src->createMateria("hi");
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	delete bob;
	delete me;
	delete src;
}

void MateriaSourceAssignmentOperator()
{
	std::cout << "===== MateriaSourceAssignmentOperator =====\n";
	AMateria* tmp;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	MateriaSource* src = new MateriaSource();
	MateriaSource* src2 = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	*src2 = *src;

	tmp = src2->createMateria("ice");
	me->equip(tmp);
	tmp = src2->createMateria("cure");
	me->equip(tmp);
	tmp = src2->createMateria("cure");
	me->equip(tmp);
	tmp = src2->createMateria("cure");
	me->equip(tmp);
	tmp = src2->createMateria("cure");
	me->equip(tmp);
	tmp = src2->createMateria("cure");
	me->equip(tmp);
	tmp = src2->createMateria("cure");
	me->equip(tmp);
	tmp = src2->createMateria("Cure");
	me->equip(tmp);
	tmp = src2->createMateria("cre");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(-1, *bob);
	me->use(50, *bob);
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
	Character* test = new Character("test");
	Character* bob = new Character("bob");
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	*test = *me;
	
	me->use(0, *bob);
	me->use(1, *bob);

	delete test;
	delete bob;
	delete me;
	delete src;
}

void	BothAssignmentOperator()
{
	AMateria* tmp;
	Character* me = new Character("me");
	Character* test = new Character("test");
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

	*test = *me;

	test->use(0, *bob);
	test->use(1, *bob);

	delete me;
	delete bob;
	delete src;
	delete src2;
	delete test;
}

int main()
{
	// atexit(a);
	subject();
	MateriaSourceAssignmentOperator();
	CharacterAssignmentOperator();
	BothAssignmentOperator();
	test1();

	MateriaSource::clearFloor();
	return 0;
}