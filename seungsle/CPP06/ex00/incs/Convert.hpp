/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:24:23 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/22 21:40:07 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>

class Convert
{
private:
	std::string _input;
	double _literal;
	int _type; // char 0 int 1 float 2 double 3 Nan 4 Inf 5
public:
	class UndefinedTypeException: public std::exception
	{
	public:
		const char* what() const throw();
	};
	Convert(/* args */);
	Convert(const char *input);
	Convert(const Convert &source);
	~Convert();
	Convert& operator=(const Convert &source);

	void setType(void);

	void toChar(void);
	void toInt(void);
	void toFloat(void);
	void toDouble(void);

	const std::string& getInput(void) const;
};

#endif