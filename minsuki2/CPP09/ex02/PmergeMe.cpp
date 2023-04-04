
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const char* const argv[], std::string strArray[]) {
	int	i = 0;
	while (argv[i + 1]) {
		const std::string& str(argv[i + 1]);
		std::size_t found = str.find_first_not_of("0123456789");
		if (found != std::string::npos
			|| str == "0") {
			throw InvaildInput();
		}
		strArray[i] = std::string(argv[i + 1]);
		++i;
	}
	strArray[i] = "";
	this->n_element = i;
}

PmergeMe::PmergeMe(const PmergeMe& obj) {
	static_cast<void>(obj);
}

PmergeMe::~PmergeMe(void) {
	this->seq_vec_.clear();
	this->seq_lst_.clear();
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	static_cast<void>(obj);
	return *this;
}

void	PmergeMe::printSequnce(const std::string str_array[]) const {
	if (str_array) {
		std::cout << "Before:\t";
		for (std::size_t i(0); i < this->n_element; ++i) {
			std::cout << str_array[i] << ' ';
		}
	}
	else {
		std::cout << "After:\t";
		for (std::list<unsigned int>::const_iterator it(this->seq_lst_.begin())
				; it != this->seq_lst_.end(); ++it) {
		// for (std::vector<unsigned int>::const_iterator it(this->seq_vec.begin())
				// ; it != this->seq_vec.end(); ++it) {
			std::cout << *it << ' ';
		}
	}
	std::cout << std::endl;
}

/*
 * lst or vec
 */

std::size_t		PmergeMe::calculateNanoPeriod(timespec& begin_ts, timespec& end_ts) {
	return 1e+9 * (end_ts.tv_sec - begin_ts.tv_sec)
										+ (end_ts.tv_nsec - begin_ts.tv_nsec);
}

void	PmergeMe::setPeriodList(timespec& begin_ts, timespec& end_ts, const std::string& which) {
	this->lst_period_ = static_cast<double>(
						this->calculateNanoPeriod(begin_ts, end_ts)) / 1e+6; // µs
}

void	PmergeMe::setPeriodVector(timespec& begin_ts, timespec& end_ts, const std::string& which) {
	this->vec_period_ = static_cast<double>(
						this->calculateNanoPeriod(begin_ts, end_ts)) / 1e+6; // µs
}

void	PmergeMe::printPeriod(void) {
	std::stringstream ss;
	ss << this->n_element;
	const std::size_t space = ss.str().size() <= 4 ? 5 : ss.str().size() + 1;
	std::cout << "Time to process a range of" << std::setw(space) << this->n_element
				<< " elemnts with std::list   : " << this->lst_period_<< " ms" << std::endl;
	std::cout << "Time to process a range of" << std::setw(space) << this->n_element
				<< " elemnts with std::vector : " << this->vec_period_<< " ms" << std::endl;
}

void	PmergeMe::pushDataList(const std::string str_array[]) {
	for (std::size_t i(0); i < this->n_element; ++i) {
		std::stringstream	ss(str_array[i]);
		unsigned int		num;
		ss >> num;
		num == 0 ? throw InvaildInput() : false;
		this->seq_lst_.push_back(num);
	}
}

void	PmergeMe::pushDataVector(const std::string str_array[]) {
	for (std::size_t i(0); i < this->n_element; ++i) {
		std::stringstream	ss(str_array[i]);
		unsigned int		num;
		ss >> num;
		num == 0 ? throw InvaildInput() : false;
		this->seq_vec_.push_back(num);
	}
}

void	PmergeMe::sortSequnceList(const std::string str_array[]) {
	pushDataList(str_array);

	insertionSort();


}

void	PmergeMe::sortSequnceVector(const std::string str_array[]) {
	static_cast<void>(str_array);
	double tmpValue = 0.0;
	for(int i = 0; i < MAX; i++){
        tmpValue += i;
    }
}

const char*	PmergeMe::InvaildInput::what(void) const throw() {
	return "Error";
}
