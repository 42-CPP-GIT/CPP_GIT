/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:08:35 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/22 12:34:14 by jinypark         ###   ########.fr       */
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
	// atexit(a);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	ICharacter* bob = new Character("bob");
	ICharacter* sam = new Character("sam");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(1, *sam);
	sam->use(0, *me);
	sam->equip(tmp);
	sam->use(0, *me);

	delete tmp;
	delete bob;
	delete me;
	delete src;
	return 0;
}