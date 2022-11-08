/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:24:20 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/08 19:03:13 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# define MSG_NOISE		"* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char *argv[]) {
	if (argc <= 1)
		std::cout << MSG_NOISE;
	for (int i = 1; i < argc; i++) {
		std::string	argvStr = argv[i];
		for (size_t len = argvStr.length(); len; len--)
			argvStr.at(len - 1) = std::toupper(argvStr.at(len - 1));
		std::cout << argvStr;
	}
	std::cout << std::endl;
	return (0);
}
