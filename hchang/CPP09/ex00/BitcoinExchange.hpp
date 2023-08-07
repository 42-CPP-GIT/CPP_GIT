/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:29:46 by hchang            #+#    #+#             */
/*   Updated: 2023/08/07 15:21:24 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <ctime>
#include <cmath>

typedef	std::map<std::string, float>	btc_currency;

class	BitcoinExchange
{
	class	CouldNotOpenFileException : public std::exception
	{
		public :
			const char*	what() const throw();
	};
	class	WrongCSVFileException : public std::exception
	{
		public :
			const char*	what() const throw();
	};
	private:
		const std::string		_inputData;
		btc_currency			_data;
		unsigned int			_year;
		unsigned int			_month;
		unsigned int			_day;
		
		void	_getCurTime();
		void	_saveCurrency(std::ifstream& currency);
		void	_checkInputFile(std::ifstream& input_file);
		bool	_checkTitle(const std::string& title1, const std::string& title2);
		bool	_checkDate(const std::string& date);
		bool	_isRightFloat(const char* end) const;
		bool	_isValidDate(const unsigned int& year, const unsigned int& month, const unsigned int& day);
		bool	_isValidFileFormat(const char* csv_file);
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