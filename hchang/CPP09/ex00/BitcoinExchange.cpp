/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:29:48 by hchang            #+#    #+#             */
/*   Updated: 2023/08/07 15:53:49 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char* inputFile)
: _inputData(inputFile)
{
	_getCurTime();
	std::ifstream	currency;
	currency.open("./data.csv");
	if (currency.fail())
	{
		throw CouldNotOpenFileException();
	}
	_saveCurrency(currency);
	currency.close();
}

BitcoinExchange::BitcoinExchange(const char* dataFile, const char* inputFile)
: _inputData(inputFile)
{
	_getCurTime();
	if (!_isValidFileFormat(dataFile))
	{
		throw WrongCSVFileException();
	}
	std::ifstream	currency;
	
	currency.open(dataFile);
	if (currency.fail())
	{
		throw CouldNotOpenFileException();
	}
	_saveCurrency(currency);
	currency.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
	{
		return (*this);
	}
	this->_data = other._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool	BitcoinExchange::_isValidFileFormat(const char* csv_file)
{
	const std::string	inputfileToString(csv_file);

	if (inputfileToString.empty())
	{
		return (false);
	}
	size_t	format_pos = inputfileToString.find(".csv");
	if (format_pos == std::string::npos || (inputfileToString.size() - format_pos) != 4)
	{
		return (false);
	}
	return (true);
}

void	BitcoinExchange::_saveCurrency(std::ifstream& currency)
{
	std::string	line;
	std::string	val[2];
	double		btcPrice;
	char		*end;

	while (std::getline(currency, line))
	{
		std::size_t	pos = line.find(',');
		if (pos == std::string::npos)
		{
			throw WrongCSVFileException();
		}
		if (line.find("date") != std::string::npos)
		{
			continue ;
		}
		val[0] = line.substr(0, pos);
		val[1] = line.substr(pos + 1, line.length());
		btcPrice = strtod(val[1].c_str(), &end);
		if (!_checkDate(val[0]) || val[1].empty() || !_isRightFloat(end))
		{
			throw WrongCSVFileException();
		}
		_data[val[0]] = static_cast<float>(btcPrice);
	}
}

bool	BitcoinExchange::_checkTitle(const std::string& title1, const std::string& title2)
{
	if (title1.empty() || title2.empty())
		return (false);
	if (title1 == "date" && title2 == "value")
		return (true);
	return (false);
}

void	BitcoinExchange::_getCurTime()
{
	char		cur_time[10];
	time_t		temp;
	struct tm	*timeptr;

	temp = time(NULL);
	timeptr = localtime(&temp);
	if (!strftime(cur_time, sizeof(cur_time), "%F", timeptr))
	{
		_year = 2023;
		_month = 0;
		_day = 0;
		return ;
	}

	std::stringstream	ss(cur_time);
	char				sep_slash;
	ss >> _year >> sep_slash >> _month >> sep_slash >> _day;
}

bool	BitcoinExchange::_isValidDate(const unsigned int& year, const unsigned int& month, const unsigned int& day)
{
	if (year < 2009 || year > _year || (year == _year && (month > _month || (month == _month && day > _day))) || \
		month < 1 || month > 12 || day < 1 || day > 31)
	{
		return (false);
	}
	if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			return (day <= 29);
		}
		else
		{
			return (day <= 28);
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return (day <= 30);
	}
	else
	{
		return (true);
	}
}

bool	BitcoinExchange::_checkDate(const std::string& date)
{
	if (date.empty())
	{
		return (false);
	}
	std::stringstream	ss(date);
	std::string			dummy;
	unsigned int		parse_date[3];
	char				sep_slash;
	bzero(&parse_date, sizeof(parse_date));
	ss >> parse_date[0] >> sep_slash >> parse_date[1] >> sep_slash >> parse_date[2] >> dummy;
	if (dummy.empty())
	{
		return (_isValidDate(parse_date[0], parse_date[1], parse_date[2]));
	}
	return (false);
}

bool	BitcoinExchange::_isRightFloat(const char* end) const
{
	if (*end == '\0')
		return (true);
	return (false);
}

float	BitcoinExchange::_getClosetData(const std::string& date)
{
	btc_currency::const_iterator it;

	it = _data.find(date);
	if (it != _data.end())
	{
		return (it->second);
	}
	else
	{
		it = _data.lower_bound(date);
		it = it == _data.begin() ? it : --it;
		return (it->second);
	}
}

void	BitcoinExchange::_checkInputFile(std::ifstream& inputFile)
{
	_getCurTime();
	std::string	line;
	char		*end;
	double		mount;
	while (std::getline(inputFile, line))
	{
		std::stringstream	ss(line);
		std::string			value[3];
		char				sep_pipe;
		ss >> value[0] >> sep_pipe >> value[1] >> value[2];
		mount = (strtod(value[1].c_str(), &end));
		if (!value[2].empty())
		{
			std::cerr << "Error: too many argument => " << value[2] << std::endl;
			continue ;
		}
		else if (_checkTitle(value[0], value[1]))
		{
			continue ;
		}
		else if (!_checkDate(value[0]))
		{
			std::cerr << "Error: bad input => " << value[0] << std::endl;
			continue ;
		}
		else if (!_isRightFloat(end))
		{
			std::cerr << "Error: bad input => " << value[1] << std::endl;
			continue ;
		}
		if (mount < 0.000000)
		{
			std::cerr << "Error: not a postive number." << std::endl;
		}
		else if (mount > 1000 || (std::floor(mount) == 1000 && (mount - std::floor(mount) < 0.0001)))
		{
			std::cout << "Error: too large a number." << std::endl;
		}
		else
		{
			std::cout << value[0] << " => " << mount << " = " << mount * _getClosetData(value[0]) << std::endl;
		}
	}
}

void	BitcoinExchange::printInputFile()
{
	std::ifstream	inputFile;
	
	inputFile.open(this->_inputData);
	if (inputFile.fail())
	{
		throw CouldNotOpenFileException();
	}
	_checkInputFile(inputFile);
	inputFile.close();
}

const char*	BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return ("Error: could not open file.");
}

const char*	BitcoinExchange::WrongCSVFileException::what() const throw()
{
	return ("Error: wrong csv file.");
}
