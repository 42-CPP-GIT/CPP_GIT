
#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string& path, const std::string& file_name);
		BitcoinExchange(const BitcoinExchange& obj);
		~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& obj);
		void				makeDatabaseCSV(const std::string& data_csv);
		void				makeInputFile(const std::string& input_file);

		static const std::map<const std::string, double>&	getDatabase(void);

	private:
		static std::map<const std::string, double>		database_;
		std::map<const std::string, double>			input_;
		// < <Y-M, D>, val >


};
