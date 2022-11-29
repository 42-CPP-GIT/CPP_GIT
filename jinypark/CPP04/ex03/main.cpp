/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:08:35 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 20:18:29 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void a()
{
	system("leaks a.out");
}

void testSubject()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void testDeepCopy()
{
	std::cout << "TestDeepCopy start\n";
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria* tmp;
	tmp = src->createMateria("ice");

	Character* me(new Character("me"));
	me->equip(tmp);

	tmp = src->createMateria("cure");
	Character* bob(new Character("bob"));
	bob->equip(tmp);

	std::cout << "[me]  before : " << me->getFirstMateria()->getType() << "\n";
	std::cout << "[bob] before : " << bob->getFirstMateria()->getType() << "\n";
	std::cout << "-----------------------------------" << "\n";
	*bob = *me;
	std::cout << "[me]  after  : " << me->getFirstMateria()->getType() << "\n";
	std::cout << "[bob] after  : " << bob->getFirstMateria()->getType() << "\n";
	std::cout << "-----------------------------------" << "\n";
	MateriaSource* src2 = new MateriaSource();
	*src2 = *src;
	src->printSlot("before src");
	src2->printSlot("before src2");
	std::cout << "-----------------------------------" << "\n";
	src->learnMateria(new Ice());
	src->printSlot("after src");
	src2->printSlot("after src2");


	delete bob;
	delete me;
	delete src;
	delete src2;
}

int main()
{
	atexit(a);

	std::string str;
	testSubject();
	std::getline(std::cin, str);
	testDeepCopy();
	std::getline(std::cin, str);
	return 0;
}