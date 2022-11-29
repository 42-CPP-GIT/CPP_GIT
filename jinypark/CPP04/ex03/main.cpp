/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:08:35 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 11:53:08 by jinypark         ###   ########.fr       */
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

int main()
{
	atexit(a);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");
	tmp = src->createMateria("fire");
	tmp = src->createMateria("lightning");
	me->equip(tmp);
	Character* bob = new Character("bob");
	*bob = *me;
	Character* sam = new Character("sam");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(1, *sam);
	sam->use(0, *me);
	sam->equip(tmp);
	sam->use(0, *me);

	std::cout << "bob: " << dynamic_cast<Character *>(bob)->slots[0] << "\n";
	std::cout << "me: " << dynamic_cast<Character *>(me)->slots[0]<< "\n";
	for(int i = 0; i < 100; ++i)
	{
		std::cout << MateriaSource::inventory[i] << "\n";
	}
	delete sam;
	delete bob;
	delete me;
	delete src;
	return 0;
}