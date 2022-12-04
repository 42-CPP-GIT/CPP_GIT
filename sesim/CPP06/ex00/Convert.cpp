/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:53:08 by sesim             #+#    #+#             */
/*   Updated: 2022/12/04 16:58:56by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <iomanip>
#include <cmath>

const char*	Convert::NonDisplayableException::what() const throw()
{
	return ("err: Cannot Printable");
}

const char*	Convert::NotValidException::what() const throw()
{
	return ("err: Wrong Input");
}

Convert::Convert(char* input) : data_(std::string(input))
{
	this->isValidInput(input);
}

Convert::Convert(const Convert& obj)
{
	*this = obj;
}

Convert& Convert::operator=(const Convert& obj)
{
	if (this == &obj)
		return (*this);
	this->data_ = obj.data_;
	this->c_ = obj.c_;
	this->i_ = obj.i_;
	this->f_ = obj.f_;
	this->d_ = obj.d_;
	return (*this);
}

bool	Convert::isRightForm(char* end) const
{
	std::string	checker(end);

	if (checker.length() == 0 || (checker.length() == 1 && checker == "f"))
		return (true);
	return (false);
}

void	Convert::print() const
{
	if (this->c_ == 0)
	{
		std::cout << "char: Non displayable\n";
		std::cout << "int: " << this->i_ << "\n";
		std::cout << "float: ";
		if (std::fabs(this->f_) - std::floor(std::fabs(this->f_)) < static_cast<float>(0.00009))
		{
			std::streamsize	ss(std::cout.precision());
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << this->f_ << "f\n";
			std::cout << std::setprecision(ss);
		}
		else
			std::cout << this->f_ << "f\n";
		std::cout << "double: ";
		if (std::fabs(this->f_) - std::floor(std::fabs(this->f_)) < std::numeric_limits<float>::epsilon())
		{
			std::streamsize	ss(std::cout.precision());
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << this->d_;
			std::cout << std::setprecision(ss);
		}
		else
			std::cout <<this->d_;
		std::cout << std::endl;
	}
	else if (this->c_ == 1)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: ";
		if (std::fabs(this->f_) - std::floor(std::fabs(this->f_)) < static_cast<float>(0.00009))
		{
			std::streamsize	ss(std::cout.precision());
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << this->f_ << "f\n";
			std::cout << std::setprecision(ss);
		}
		else
			std::cout << this->f_ << "f\n";
		std::cout << "double: ";
		if (std::fabs(this->f_) - std::floor(std::fabs(this->f_)) < std::numeric_limits<float>::epsilon())
		{
			std::streamsize	ss(std::cout.precision());
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << this->d_;
			std::cout << std::setprecision(ss);
		}
		else
			std::cout <<this->d_;
		std::cout << std::endl;
	}
	else if (this->c_ == 2)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: ";
		if (std::fabs(this->f_) - std::floor(std::fabs(this->f_)) < std::numeric_limits<float>::epsilon())
		{
			std::streamsize	ss(std::cout.precision());
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << this->d_;
			std::cout << std::setprecision(ss);
		}
		else
			std::cout <<this->d_;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "char: '" << this->c_ << "'\n";
		std::cout << "int: " << this->i_ << "\n";
		std::cout << "float: ";
		if (std::fabs(this->f_) - std::floor(std::fabs(this->f_)) < static_cast<float>(0.00009))
		{
			std::streamsize	ss(std::cout.precision());
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << this->f_ << "f\n";
			std::cout << std::setprecision(ss);
		}
		else
			std::cout << this->f_ << "f\n";
		std::cout << "double: ";
		if (std::fabs(this->f_) - std::floor(std::fabs(this->f_)) < std::numeric_limits<float>::epsilon())
		{
			std::streamsize	ss(std::cout.precision());
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << this->d_;
			std::cout << std::setprecision(ss);
		}
		else
			std::cout <<this->d_;
		std::cout << std::endl;
	}
}

void	Convert::isValidInput(char *input)
{
	if (this->data_.length() == 1 && !(std::isdigit(this->data_.at(0))))
		throw NonDisplayableException();
	char	*end;
	double	val(strtod(input, &end));

	if ((this->isNan(val) || this->isInf(val)) && this-isRightForm(end))
	{
		this->c_ = 1;
		this->f_ = static_cast<float>(val);
		this->d_ = val;
		return ;
	}
	if (end && !this->isRightForm(end))
		throw NotValidException();
	if (val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))
	{
		this->c_ = 1;
		this->f_ = static_cast<float>(val);
		this->d_ = val;
		return;
	}
	if (this->data_.find(".") != std::string::npos && val > static_cast<double>(__FLT_MAX__))
	{
		this->c_ = 2;
		this->d_ = val;
		return ;
	}
	if (val > static_cast<double>(126) || val < static_cast<double>(32))
	{
		this->c_ = 0;
		this->i_ = static_cast<int>(val);
		this->f_ = static_cast<float>(val);
		this->d_ = val;
		return ;
	}
	this->c_ = static_cast<char>(val);
	this->i_ = static_cast<int>(val);
	this->f_ = static_cast<float>(val);
	this->d_ = val;
}

bool	Convert::isNan(double val) const
{
	if (val != val)
		return (true);
	return (false);
}

bool	Convert::isInf(double val) const
{
	if (val != 0 && val * 2 == val)
		return (true);
	return (false);
}

Convert::~Convert()
{
}
