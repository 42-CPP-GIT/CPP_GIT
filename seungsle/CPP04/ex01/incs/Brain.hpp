/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:51:29 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/17 23:42:44 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain(/* args */);
	Brain(const Brain &Brain);
	~Brain();
	Brain& operator = (const Brain &source);
};

#endif