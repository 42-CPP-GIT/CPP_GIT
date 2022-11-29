/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:15:52 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/29 16:28:13 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <iomanip>

class Brain
{
private:
	std::string		ideas[100];
	unsigned int	ideaCnt;
public:
	Brain();
	~Brain();
	Brain(const Brain &obj);
	Brain	&operator=(Brain const &obj);
	void				setIdeas(const std::string& idea);
	void				setIdeas(const std::string* idea);
	const std::string	getIdeas(unsigned int i) const;
	const std::string*	getIdeas(void) const;
	unsigned int		getIdeaCnt(void) const;
	void				showIdeas(void) const;
};



#endif