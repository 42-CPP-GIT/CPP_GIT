#pragma once

#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <ctime>

typedef	std::map<std::string, float>	btc_currency;

class	BitcoinExchange
{
	class	CouldNotOpenFileException : public std::exception
	{
		public :
			const char*	what() const throw();
	};
	class	WrongCsvFileException : public std::exception
	{
		public :
			const char*	what() const throw();
	};
	private:
		std::string		_input_data;
		btc_currency	_data;
		unsigned int	_year;
		unsigned int	_month;
		unsigned int	_day;
		
		void	_printData();
		void	_getCurTime();
		void	_storeCurrency(std::ifstream& currency);
		void	_checkInputFile(std::ifstream& input_file);
		bool	_checkTitle(const std::string& title1, const std::string& title2);
		bool	_checkDate(const std::string& date);
		bool	_isOnlyDigit(const std::string& value);
		bool	_isValidDate(const unsigned int& year, const unsigned int& month, const unsigned int& day);
		bool	_checkValue(const std::string& value);
		float	_getClosetData(const std::string& date);
	
	public:
		BitcoinExchange(const char* input_file);
		BitcoinExchange(const char* input_file, const char* data_file);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	printInputFile();
};