/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:43:54 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/01 15:29:30 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		// HumanA bob;						// private으로 막아놓기
		// HumanA bob("Bob", NULL); 		// NULL은 어차피 컴파일 에러

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	// std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		// Weapon club = Weapon();			// private으로 막아놓기

		HumanB jim("Jim");

		// jim.setWeapon(club);				// 주석 처리해도 seg. fault 없어야 함
		jim.attack();
		club.setType("some other type of club");
		jim.setWeapon(club);				// 중간에 추가하면 반영되어야 함
		jim.attack();
	}
	// std::cout << std::endl;
	return 0;
}
