
#include "BitcoinExchange.hpp"

std::map<const std::string, double>		BitcoinExchange::database_;

const std::map<const std::string, double>&		BitcoinExchange::getDatabase(void) {
	return BitcoinExchange::database_;
}

BitcoinExchange::BitcoinExchange(const std::string& path) {
	makeDatabaseCSV(path + "data.csv");
}

void	BitcoinExchange::makeDatabaseCSV(const std::string& data_csv) {
	std::ifstream file(data_csv);
	if (file.fail()) {
		throw FaildOpenFile();
	} else {
		std::string line;

		std::getline(file, line, ',');
		line == "date" ? true : throw FomatIsWrong();
		std::getline(file, line, '\n');
		line == "exchange_rate" ? true : throw FomatIsWrong();

		std::string			old_date = "0000-01-01";
		while (std::getline(file, line, '\n')) {
			std::istringstream	ss(line);
			std::string			date;
			double				price;

			std::getline(ss, date, ',');
			if (isInvaildDate(date, old_date)) {
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			else if (line.find(',') == std::string::npos) {
				throw WrongInput();
			}
			ss >> price;
			if(ss.fail()) {
				throw FaildConvertNumber();
			}
			else if (price < 0) {
				throw NegativeNumber();
			}
			BitcoinExchange::database_.insert(std::make_pair(date, price));
			old_date = date;
		}
		file.close();
	}
	if (BitcoinExchange::database_.empty())
		throw EmptyDatabase();
}

bool	BitcoinExchange::isLeapYear(int y) {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400) == 0;
}

bool	BitcoinExchange::isInvaildDate(const std::string& date, const std::string& old_date) {
	std::istringstream	ss_date(date);

	std::string			year, month, day;
	int					y;

	static_cast<void>(old_date);
	if (date < old_date)
		return true;
	std::getline(ss_date, year, '-');
	if (year.length() != 4)
		return true;

	std::getline(ss_date, month, '-');
	if (month.length() != 2 || (month < "01" || "12" < month))
		return true;

	std::getline(ss_date, day, ' ');
	if ((day.length() != 2
		|| ((day < "01" || "31" < day))
		|| ((month == "02") && day > "29"))
		|| ((month == "04" || month == "06" || month == "09" || month == "11") && day == "31"))
		return true;
	if (month == "02" && day == "29") { // 윤년 2월 29일 가능
		std::istringstream	ss(year);
		ss >> y;
		if (!isLeapYear(y)) {
			return true;
		}
	}
	return false;
}

bool	BitcoinExchange::isInvaildValue(double value, double price) {
	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return true;
	}
	// over flow를 위해 곱해서 비교 x
	else if (value * price > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return true;
	}
	return false;
}

void	BitcoinExchange::calculateInput(const std::string& input_file) {
	std::ifstream file(input_file);
	if(file.fail()) {
		throw FaildOpenFile();
	} else {
		std::string line;
		std::getline(file, line, '|');
		line == "date " ? true : throw FomatIsWrong();
		std::getline(file, line, '\n');
		line == " value" ? true : throw FomatIsWrong();

		std::string			old_date = "0000-01-01";
		while(std::getline(file, line, '\n')) {
			std::istringstream	ss(line);
			std::string			date;
			double				value;
			std::getline(ss, date, '|');
			if (isInvaildDate(date, old_date)) {
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			else if (line.find(" | ") == std::string::npos) {
				std::cout << "Error: wrong input => \" | \" " << std::endl;
				continue;
			}
			ss >> value;
			if(ss.fail()) {
				std::cout <<  "Error: stringstream -> double is Failded" << std::endl;
				continue;
			}
			/* database_ 비어있거나 더 작은 데이터가 없을 때 */
			else if (BitcoinExchange::database_.size() == 1 && BitcoinExchange::database_.begin()->first > date) {
				std::cout << "Error: no lower date => " << date << std::endl;
				continue;
			}

			/* iterator lower_bound 설정 */
			std::map<const std::string, double>::const_iterator it_low = BitcoinExchange::database_.lower_bound(date);
			--it_low;

			if (isInvaildValue(value, it_low->second)) {
				continue;
			}
			std::cout << date << " => " << value << " = " << std::setprecision(10) << value * it_low->second << std::endl;
			old_date = date;
		}
		file.close();
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	*this = obj;
}

BitcoinExchange::~BitcoinExchange(void) { }

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& obj) {
	return *this;
}

const char*		BitcoinExchange::FaildConvertNumber::what(void) const throw() {
	return "Error: stringstream -> double is Failded";
}

const char*		BitcoinExchange::FaildOpenFile::what(void) const throw() {
	return "Error: Unable to open file";
}

const char*		BitcoinExchange::FomatIsWrong::what(void) const throw() {
	return "Error: fomat of file is wrong";
}
const char*		BitcoinExchange::WrongInput::what(void) const throw() {
	return "Error: wrong input => \',\' ";
}
const char*		BitcoinExchange::EmptyDatabase::what(void) const throw() {
	return "Error: Database is Empty";
}
const char*		BitcoinExchange::NegativeNumber::what(void) const throw() {
	return "Error: price is negative number";
}
