/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:11 by hchang            #+#    #+#             */
/*   Updated: 2022/11/22 15:12:07 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void a()
{
	system("leaks Materia");
}

void test1(void)
{

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// src->learnMateria(new Ice());
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure()); // <- 못들어감

	
	Character* me = new Character("me");
	
	AMateria* tmp;
	AMateria* tmp1;
	
	tmp = src->createMateria("ice");
	// std::cout << tmp->getType() << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp1 = tmp->clone();
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
	
	delete tmp1;
	delete bob;
	delete me;
	delete src;
}

void test2(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* me = new Character("me");

	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	Character* hchang = me;

	hchang->use(0, *me);
	hchang->use(1, *me);


	// IMateriaSource* tmp_src = src;

	// tmp = tmp_src->createMateria("cure");
	// hchang->equip(tmp);
	// hchang->use(2, *me);
	// hchang->use(3, *me);

	
	delete me;
	delete src;
}


int main()
{
	// atexit(a);
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* me = new Character("me");
	
	MateriaSource* src2 = new MateriaSource();

	*src2 = *src;

	AMateria* tmp;
	tmp = src2->createMateria("ice");
	me->equip(tmp);
	tmp = src2->createMateria("cure");
	me->equip(tmp);

	Character* hchang = new Character("hchang");
	std::cout << "bro\n";
	*hchang = *me;
	std::cout << "bro1\n";

	tmp = src2->createMateria("hi");

	hchang->use(0, *me);
	hchang->use(1, *me);
	hchang->use(2, *me);


	delete me;
	delete src;
	delete src2;


	return 0;
}