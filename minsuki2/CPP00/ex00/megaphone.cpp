/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:24:20 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/05 16:02:07 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# define MSG_NOISE		"* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char *argv[]) {
	if (argc <= 1)
		std::cout << MSG_NOISE;
	for (int i = 1; i < argc; i++) {
		std::string	argvStr = argv[i];
		for (std::string::iterator it(argvStr.begin()); it != argvStr.end(); it++) {
			*it = std::toupper(*it);
		}
		std::cout << argvStr;
	}
	std::cout << std::endl;
	return (0);
}
