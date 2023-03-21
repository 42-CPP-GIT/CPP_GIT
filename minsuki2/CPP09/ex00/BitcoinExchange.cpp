
#include "BitcoinExchange.hpp"

std::map<const std::string, double>		BitcoinExchange::database_;

const std::map<const std::string, double>&		BitcoinExchange::getDatabase(void) {
	return BitcoinExchange::database_; 
}

BitcoinExchange::BitcoinExchange(const std::string& path, const std::string& file_name) {
	const std::string& data_csv = path + "data.csv";
	makeDatabaseCSV(data_csv);
	makeInputFile(file_name);
}

void	BitcoinExchange::makeDatabaseCSV(const std::string& data_csv) {
	std::ifstream file(data_csv);
	if (file.fail()) {
		std::cout << "Error: Unable to open file" << std::endl;
	} else {
		std::string line;
		while (std::getline(file, line, '\n')) {
			std::istringstream	ss(line);
			std::string			date;
			double			price;
			std::getline(ss, date, ',');
			ss >> price;
			BitcoinExchange::database_.insert(std::make_pair(date, price));
		}
		file.close();
	}
}

void	BitcoinExchange::makeInputFile(const std::string& input_file) {
	static_cast<void>(input_file);
	// std::ifstream file(input_file);
	// if(file.fail()) {
	//     std::cout << "Error: Unable to open file" << std::endl;
	// } else {
	//     while(getline(file, line, '\n')) {
	//         std::cout << line << std::endl;
	//         data_csv
	//         res += line;
	//     }
	//     file.close();
	// }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	*this = obj;
}

BitcoinExchange::~BitcoinExchange(void) { }

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& obj) {
	for (std::map<const std::string, double>::const_iterator it(obj.input_.begin())
		; it != obj.input_.end(); ++it) {
		this->input_.insert(std::make_pair(it->first, it->second));
	}
	return *this;
}
