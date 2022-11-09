/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:20:58 by junhjeon          #+#    #+#             */
/*   Updated: 2022/10/31 16:56:18 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*z1;

	z1 = newZombie("z1");
	z1 -> announce();
	randomChump("z2");
	delete z1;
	return (0);
}
