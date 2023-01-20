/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:47 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/20 21:39:21 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP
# define MSG_COVERSION					"[Conversion] "
# define MSG_DEFAULT_CONSTRUCT			"Default Constructor"
# define MSG_COPY_CONSTRUCT				"Copy Constructor"
# define MSG_COPY_ASSIGN_OPERATE		"Copy assignment operator"
# define MSG_DESTRCUT					"Destructor"
# define MSG_CHAR						"char: "
# define MSG_INT						"int: "
# define MSG_FLOAT						"float: "
# define MSG_DOUBLE						"double: "
# define MSG_IMPOSSIBLE					"impossible"
# define MSG_NON_DISPLAY				"Non displayable"



enum e_bit { BIT_FLOAT_EXPONENT = 0b11111111 << 23
			, BIT_INT_MAX_EXPONENT = 0b10011110 << 23
			, BIT_FLOAT_MANTISSA = 0b11111111111111111111111 };

enum e_rtn { FLAG_REG, FLAG_NAN = 0b10, FLAG_INF = 0b100 };
# include <iostream>
# include <cctype>
# include <cmath>
# include <iomanip>
# include "color.h"


class Conversion {
	public:
		Conversion(double val, const std::string& end);
		Conversion(const Conversion& obj);
		Conversion&	operator=(const Conversion& obj);
		~Conversion(void);
		const char&			getFlag(void) const;
		const char&			getChar(void) const;
		const int&			getInt(void) const;
		const float&		getFloat(void) const;
		const double&		getDouble(void) const;

		void				printChar(void) const;
		void				printInt(void) const;
		void				printFloat(void) const;
		void				printDouble(void) const;
	public:
		class ArgumentCountsException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class ArgumentInputException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class EndPointerException: public std::exception {
			public:
				const char* what(void) const throw();
		};
		class JustFloatCharException: public std::exception {
			public:
				const char* what(void) const throw();
		};

	private:
		char					flag_;
		const	char			val_char_;
		const	int				val_int_;
		const	float			val_float_;
		const	double			val_double_;
	private:
		Conversion(void);
		void	setFlag(const float val);
		void	checkVaildArgument(const double& val, const std::string& end);
		void	checkNeedPrecision(const double value) const;
};

#endif

