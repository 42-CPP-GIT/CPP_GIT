#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <string>
#include <cstring>

const char*	BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return ("Error: could not open file.");
}

const char*	BitcoinExchange::WrongCsvFileException::what() const throw()
{
	return ("Error: wrong csv file.");
}

BitcoinExchange::BitcoinExchange(const char* input_file)
: _input_data(input_file)
{
	std::ifstream	currency;
	
	currency.open("./cpp_09/data.csv");
	if (currency.fail())
	{
		throw CouldNotOpenFileException();
	}
	_storeCurrency(currency);
	currency.close();
}

BitcoinExchange::BitcoinExchange(const char* input_file, const char* data_file)
: _input_data(input_file)
{
	if (!_isValidFileFormat(data_file))
	{
		throw WrongCsvFileException();
	}
	std::ifstream	currency;
	
	currency.open(data_file);
	if (currency.fail())
	{
		throw CouldNotOpenFileException();
	}
	_storeCurrency(currency);
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
	const std::string	inputfile_to_string(csv_file);

	if (inputfile_to_string.empty())
	{
		return (false);
	}
	size_t	format_pos = inputfile_to_string.find(".csv");
	if (format_pos == std::string::npos || (inputfile_to_string.size() - format_pos) != 4)
	{
		return (false);
	}
	return (true);
}

void	BitcoinExchange::_storeCurrency(std::ifstream& currency)
{
	std::string	line;
	std::string	val[2];
	while (std::getline(currency, line))
	{
		std::size_t	pos = line.find(',');
		if (pos == std::string::npos)
		{
			throw WrongCsvFileException();
		}
		if (line.find("date") != std::string::npos)
		{
			continue ;
		}
		val[0] = line.substr(0, pos);
		val[1] = line.substr(pos + 1, line.length());
		_data[val[0]] = atof(val[1].c_str());
	}
}

/*
	=========================
	TODO: Is this really need?
*/
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
	char		s[10];
	time_t		temp;
	struct tm	*timeptr;

	temp = time(NULL);
	timeptr = localtime(&temp);
	if (!strftime(s, sizeof(s), "%F", timeptr))
	{
		_year = 2023;
		_month = 0;
		_day = 0;
		return ;
	}

	std::stringstream	ss(s);
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
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
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
	else
	{
		return (false);
	}
}

bool	BitcoinExchange::_isOnlyDigit(const std::string& value)
{
	for (std::size_t i(0); i < value.length(); ++i)
	{
		if (!std::isdigit(value.at(i)) && value.at(i) != '-')
		{
			return (false);
		}
	}
	return (true);
}

bool	BitcoinExchange::_checkValue(const std::string& value)
{
	if (value.empty())
	{
		return (false);
	}
	std::size_t	dot_pos = value.find('.');
	std::string	float_val = dot_pos != std::string::npos ? value.substr(0, dot_pos) + value.substr(dot_pos + 1, value.length()) : value;
	if (!_isOnlyDigit(value.substr(0, dot_pos) + value.substr(dot_pos + 1, value.length())))
	{
		return (false);
	}
	return (true);
}

float	BitcoinExchange::_getClosetData(const std::string& date)
{
	btc_currency::const_iterator it;

	it  = _data.find(date);
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

void	BitcoinExchange::_checkInputFile(std::ifstream& input_file)
{
	_getCurTime();
	std::string	line;
	while (std::getline(input_file, line))
	{
		std::stringstream	ss(line);
		std::string			value[3];
		char				sep_pipe;
		float				mount(0.0f);
		ss >> value[0] >> sep_pipe >> value[1] >> value[2];
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
		else if (!_checkValue(value[1]))
		{
			std::cerr << "Error: bad input => " << value[1] << std::endl;
			continue ;
		}
		mount = atof(value[1].c_str());
		if (mount < 0.000000f)
		{
			std::cerr << "Error: not a postive number." << std::endl;
		}
		else if (mount > 1000.000000f)
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
	std::ifstream	input_file;
	
	input_file.open(this->_input_data);
	if (input_file.fail())
	{
		throw CouldNotOpenFileException();
	}
	_checkInputFile(input_file);
	input_file.close();
}
