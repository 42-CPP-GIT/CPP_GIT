
#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#ifndef PATH
 #define PATH "../"
#endif

class BitcoinExchange {
	public:
		BitcoinExchange(std::ifstream& data_file);
		BitcoinExchange(const BitcoinExchange& obj);
		~BitcoinExchange(void);
		BitcoinExchange&	operator=(const BitcoinExchange& obj);

		static const std::string&							getPath(void);
		static const std::map<const std::string, float>&	getDatabase(void);

		void	calculateInput(const char* input_name);

		const std::string		badInput(const std::string& date) const;
		class FaildConvertNumber : public std::exception {
			const char*		what(void) const throw();
		};
		class FaildOpenFile : public std::exception {
			const char*		what(void) const throw();
		};
		class FomatIsWrong : public std::exception {
			const char*		what(void) const throw();
		};
		class WrongInput : public std::exception {
			const char*		what(void) const throw();
		};
		class EmptyDatabase : public std::exception {
			const char*		what(void) const throw();
		};
		class NegativeNumber : public std::exception {
			const char*		what(void) const throw();
		};
		class InvaildExtension : public std::exception {
			const char*		what(void) const throw();
		};

	private:
		static const std::string						path_;
		static std::map<const std::string, float>		database_;

		bool		isInvaildDate(const std::string& date, const std::string& old_date);
		bool		isInvaildValue(float value, float price);
		bool		isLeapYear(int y);
		void		checkTitle(std::ifstream& input_file, std::string& line
								, const std::string& target, const char delimiter) const;

};
