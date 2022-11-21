/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:08:35 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/21 09:12:07 by jinypark         ###   ########.fr       */
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
	AMateria* tmp1;
	AMateria* tmp2;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	ICharacter* bob = new Character("bob");
	ICharacter* sam = new Character("sam");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(1, *sam);
	sam->use(0, *me);
	sam->equip(tmp1);
	sam->use(0, *me);

	delete tmp1;
	delete tmp2;
	delete bob;
	delete me;
	delete src;
	return 0;
}