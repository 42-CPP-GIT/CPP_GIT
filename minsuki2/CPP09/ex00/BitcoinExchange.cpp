
#include "BitcoinExchange.hpp"

std::map<const std::string, float>		BitcoinExchange::database_;
const std::string						BitcoinExchange::path_ = PATH;

void	BitcoinExchange::invaildValueChecker(float value) {
	if (value <= 0.0f) {
		throw NegativeNumber();
	} else if (value >= 1000.0f) {
		throw TooLargeNumber();
	}
}

bool	BitcoinExchange::isLeapYear(int y) {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400) == 0;
}

bool BitcoinExchange::isOnlyNumber(const std::string& target) {
	return target.size() && target.find_first_not_of("0123456789") == std::string::npos;
}

bool	BitcoinExchange::isInvaildDate(const std::string& date, const std::string& old_date) {
	std::istringstream	ss_date(date);

	std::string			year, month, day;
	int					y;

	if (date < old_date)
		return true;
	std::getline(ss_date, year, '-');
	if (!isOnlyNumber(year) || (year.length() != 4)) {
		return true;
	}
	std::getline(ss_date, month, '-');
	if (!isOnlyNumber(month) || month.length() != 2
							 || (month < "01" || "12" < month)) {
		return true;
	}
	std::getline(ss_date, day, ' ');
	if (!isOnlyNumber(day) || day.length() != 2
						   || (day < "01" || "31" < day)) {
		return true;
	} else if ((month == "02" && day > "29")
				|| ((month == "04" || month == "06"
						|| month == "09" || month == "11") && day == "31")) {
		return true;
	} else if (month == "02" && day == "29") { // 윤년 2월 29일 가능
		std::istringstream	ss(year);
		ss >> y;
		if (!isLeapYear(y)) {
			return true;
		}
	}
	return false;
}

BitcoinExchange::BitcoinExchange(std::ifstream& data_file) {
	/* makeDatabaseCSV */
	std::string			line;
	std::getline(data_file, line, ',');
	line == "date" ? true : throw FomatIsWrong();
	std::getline(data_file, line, '\n');
	line == "exchange_rate" ? true : throw FomatIsWrong();

	std::string			old_date = "0000-01-01";
	while (std::getline(data_file, line, '\n')) {
		std::istringstream	ss(line);
		std::string			date;
		float				price;

		std::getline(ss, date, ',');
		if (isInvaildDate(date, old_date)) {
			throw badInput(date);
		} else if (line.find(',') == std::string::npos) {
			throw wrongInput("','");
		}
		ss >> price;
		if(ss.fail()) {
			throw FaildConvertNumber();
		} else if (price < 0) {
			throw NegativeNumber();
		}
		BitcoinExchange::database_.insert(std::make_pair(date, price));
		old_date = date;
	}
	if (BitcoinExchange::database_.empty()) {
		throw EmptyDatabase();
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	static_cast<void>(obj);
}

BitcoinExchange::~BitcoinExchange(void) {
	this->database_.clear();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& obj) {
	static_cast<void>(obj);
	return *this;
}

const std::map<const std::string, float>&		BitcoinExchange::getDatabase(void) {
	return BitcoinExchange::database_;
}
const std::string&								BitcoinExchange::getPath(void) {
	return BitcoinExchange::path_;
}

void	BitcoinExchange::checkTitle(std::ifstream& input_file, std::string& line
									, const std::string& target, const char delimiter) const {
	std::getline(input_file, line, delimiter);
	if (line != target) {
		input_file.close();
		throw FomatIsWrong();
	}
}

void	BitcoinExchange::calculateInput(const char* input_name) {
	std::ifstream		input_file(input_name);
	if(input_file.fail()) {
		throw FaildOpenFile();
	}
	std::string		line;
	checkTitle(input_file, line, "date ", '|');
	checkTitle(input_file, line, " value", '\n');
	std::string			old_date = "0000-01-01";
	while(std::getline(input_file, line, '\n')) {
		std::istringstream	ss(line);
		std::string			date;
		float				value;
		std::getline(ss, date, '|');
		try {
			if (isInvaildDate(date, old_date)) {				/* 날짜 검사 */
				throw badInput(date);
			} else if (line.find(" | ") == std::string::npos) { /* 포맷 검사 */
				throw wrongInput("\" | \"");
			}
			ss >> value;
			if (ss.fail()) {
				std::cout << "Error: stringstream -> float was failed" << std::endl;
				continue;
			} else if (BitcoinExchange::database_.size() == 1
					&& BitcoinExchange::database_.begin()->first > date) {
				throw noLowerDate(date);
			}
			std::map<const std::string, float>::const_iterator it_low = BitcoinExchange::database_.lower_bound(date);
			if (BitcoinExchange::database_.begin() == it_low) {
				throw noLowerDate(date);
			}
			--it_low;
			invaildValueChecker(value);
			std::cout << date.substr(0, 10) << " => " << value << " = "
					  << std::setprecision(2) << value * it_low->second << std::endl;
			old_date = date;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
			continue;
		} catch (const std::string& s) {
			std::cout << s << std::endl;
			continue;
		}
	}
	input_file.close();
}


const std::string		BitcoinExchange::badInput(const std::string& date) const {
	return "Error: bad input => " + date;
}
const std::string		BitcoinExchange::noLowerDate(const std::string& date) const {
	return "Error: no lower date => " + date;
}
const std::string		BitcoinExchange::wrongInput(const std::string& input) const {
	return "Error: wrong input => " + input;
}
const char*		BitcoinExchange::FaildConvertNumber::what(void) const throw() {
	return "Error: stringstream -> float was failed.";
}
const char*		BitcoinExchange::FaildOpenFile::what(void) const throw() {
	return "Error: Unable to open file.";
}
const char*		BitcoinExchange::FomatIsWrong::what(void) const throw() {
	return "Error: format of file is wrong.";
}
const char*		BitcoinExchange::EmptyDatabase::what(void) const throw() {
	return "Error: Database is Empty";
}
const char*		BitcoinExchange::NegativeNumber::what(void) const throw() {
	return "Error: not a positive number.";
}
const char*		BitcoinExchange::InvaildExtension::what(void) const throw() {
	return "Error: The extension is not .csv";
}
const char*		BitcoinExchange::TooLargeNumber::what(void) const throw() {
	return "Error: too large a number." ;
}
