/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:01:22 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/27 02:21:03 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>
# include <numeric>

class Span {
	public:
		Span(unsigned int n);
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span(void);

		void			addNumber(unsigned int n);
		void			addNumber(const std::vector<int>::const_iterator& it_begin
								  , const std::vector<int>::const_iterator& it_end);
		void			showSpanNumber(void) const;
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		const std::vector<unsigned int>&		getPocket(void) const;

		class OverMaximumStoreException : public std::exception {
			const char*		what(void) const throw();
		};
		class AddNumberTwiceException : public std::exception {
			const char*		what(void) const throw();
		};
		class AtLeastTwoException : public std::exception {
			const char*		what(void) const throw();
		};
	private:
		unsigned int		N_;
		std::vector<unsigned int>	pocket_;
		Span(void);
};

# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#endif
