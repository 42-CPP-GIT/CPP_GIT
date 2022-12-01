/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:08:11 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/22 19:25:11 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

class Span
{
	private :
		std::vector<int>  *store_;
		unsigned int size_;

	public :
		Span(unsigned int n);
		~Span();
		Span(const Span& copy);
		Span& operator =(const Span& s);
		std::vector<int>  *getStore() const;
		unsigned int  getSize() const;
		void	addNumber( unsigned int n );
		std::string 	error(std::string str) const;
		int shortestSpan( void ) const;
		int longestSpan( void ) const;
		void		addNumberAll(int *x, unsigned int size);
};
