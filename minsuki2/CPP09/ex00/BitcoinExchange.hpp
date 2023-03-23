
#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#ifndef PATH
 #define PATH "../"
#endif

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string& path);
		BitcoinExchange(const char* data_path_name);
		BitcoinExchange(const BitcoinExchange& obj);
		~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& obj);
		void				makeDatabaseCSV(const std::string& data_csv);
		void				calculateInput(const std::string& input_file);

		static const std::map<const std::string, float>&	getDatabase(void);
		const std::map<const std::string, float>&			getInput(void);

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
		static std::map<const std::string, float>		database_;
		// std::map<const std::string, float>				input_;
		// < <Y-M, D>, val >
		//
		bool		isInvaildDate(const std::string& date, const std::string& old_date);
		bool		isInvaildValue(float value, float price);
		bool		isLeapYear(int y);

};
