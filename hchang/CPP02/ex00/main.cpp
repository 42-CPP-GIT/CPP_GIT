/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:58:00 by hchang            #+#    #+#             */
/*   Updated: 2022/11/09 13:33:42 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed	a;		// 디폴트 생성자
	Fixed	b(a);	// 복사 생성자 (만들어주지 않으면 컴파일러에서 기본적으로 복사생성자를 만들어줌)
	Fixed	c;		// 디폴트 생성자
	
	c = b; // 대입연산자 오버로딩
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}