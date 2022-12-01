/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:44:14 by hojinjang         #+#    #+#             */
/*   Updated: 2022/11/18 16:12:48 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# define RESET "\033[0m"
# define IT "\e[0;3m"
# define RED "\e[0;31m"
# define GRN "\e[0;33m"

#include <iostream>

class WrongAnimal
{
protected:
	std::string	_type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& obj);
	WrongAnimal& operator=(const WrongAnimal& obj);
	~WrongAnimal();
	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
