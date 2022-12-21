/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:43:54 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/23 18:20:06 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#define MSG_BRAIN	"HI THIS IS BRAIN"
#define MSG_ENDL	'\n'

int main(void) {
	std::string stringORI(MSG_BRAIN);
	std::string &stringREF = stringORI;
	std::string *stringPTR = &stringORI;
	std::cout << "< Print of memory address >" << MSG_ENDL;
	std::cout << "String Variable  : " << &stringORI << MSG_ENDL;
	std::cout << "String Reference : " << &stringREF << MSG_ENDL;
	std::cout << "String Pointer   : " << stringPTR << MSG_ENDL;	// string의 주소를 출력
	std::cout << std::endl;

	std::cout << "< Print of value >" << MSG_ENDL;
	std::cout << "String Variable  : " << stringORI << MSG_ENDL;
	std::cout << "String Reference : " << stringREF << MSG_ENDL;
	std::cout << "String Pointer   : " << *stringPTR << MSG_ENDL;
	std::cout << std::endl;
	return 0;
}
