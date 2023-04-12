
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
		const std::string		noLowerDate(const std::string& date) const;
		const std::string		wrongInput(const std::string& input) const;
		class FaildConvertNumber : public std::exception {
			const char*		what(void) const throw();
		};
		class FaildOpenFile : public std::exception {
			const char*		what(void) const throw();
		};
		class FomatIsWrong : public std::exception {
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
		class TooLargeNumber : public std::exception {
			const char*		what(void) const throw();
		};

	private:
		static const std::string						path_;
		static std::map<const std::string, float>		database_;

		bool		isInvaildDate(const std::string& date, const std::string& old_date);
		void		invaildValueChecker(float value);
		bool		isLeapYear(int y);
		bool		isOnlyNumber(const std::string& target);
		void		checkTitle(std::ifstream& input_file, std::string& line
								, const std::string& target, const char delimiter) const;

};
