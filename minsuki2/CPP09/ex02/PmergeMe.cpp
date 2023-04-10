#include "PmergeMe.hpp"

// template<typename T>
// static void	printContainer(T& target) {
//     std::cerr << "-> ";
//     for (typename T::iterator it(target.begin())
//             ; it != target.end(); ++it) {
//         std::cerr << std::setw(2) << *it << ' ';
//     }
//     std::cerr << '\n';
// }

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
	this->seq_vector_.clear();
	this->seq_deque_.clear();
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	static_cast<void>(obj);
	return *this;
}

void	PmergeMe::printSequnce(const std::string str_array[]) const {
	if (str_array) {
		std::cout << "Before:\t";
		for (std::size_t i = 0; i < this->n_element; ++i) {
			std::cout << str_array[i] << ' ';
		}
	}
	else {
		std::cout << "After:\t";
		for (std::deque<unsigned int>::const_iterator it(this->seq_deque_.begin())
				; it != this->seq_deque_.end(); ++it) {
		// for (std::vector<unsigned int>::const_iterator it(this->seq_vector_.begin())
		//         ; it != this->seq_vector_.end(); ++it) {
			std::cout << std::fixed << std::setprecision(5) << *it << ' ';
		}
	}
	std::cout << std::endl;
}

std::size_t		PmergeMe::calculateNanoPeriod(timespec& begin_ts, timespec& end_ts) {
	return 1e+9 * (end_ts.tv_sec - begin_ts.tv_sec)
										+ (end_ts.tv_nsec - begin_ts.tv_nsec);
}

void	PmergeMe::setPeriodDeque(timespec& begin_ts, timespec& end_ts) {
	this->lst_period_ = static_cast<double>(
						this->calculateNanoPeriod(begin_ts, end_ts)) / 1e+6; // µs
}

void	PmergeMe::setPeriodVector(timespec& begin_ts, timespec& end_ts) {
	this->vec_period_ = static_cast<double>(
						this->calculateNanoPeriod(begin_ts, end_ts)) / 1e+6; // µs
}

void	PmergeMe::printPeriod(void) {
	std::stringstream ss;
	ss << this->n_element;
	const std::size_t space = ss.str().size() < 5 ? 5 : ss.str().size() + 1;
	std::cout << "Time to process a range of" << std::setw(space) << this->n_element
				<< " elemnts with std::deque : " << this->lst_period_<< " ms" << std::endl;
	std::cout << "Time to process a range of" << std::setw(space) << this->n_element
				<< " elemnts with std::vector : " << this->vec_period_<< " ms" << std::endl;
}


void	PmergeMe::InsertionSortDeque(std::size_t p1, std::size_t p2) {
	std::size_t  j;
	unsigned int key;
	for (std::size_t i = p1; i < p2; ++i) {
		key = this->seq_deque_.at(i + 1);
		for (j = i + 1
			; j > p1 && this->seq_deque_.at(j - 1) > key; --j) {
		  this->seq_deque_.at(j) = this->seq_deque_.at(j - 1);
		}
		this->seq_deque_.at(j) = key;
	}
	// printContainer(this->seq_deque_);
}

void	PmergeMe::mergePartDeque(std::size_t p1, std::size_t p2, std::size_t p3) {
	const std::size_t left_mid_len = p2 - p1 + 1;
	const std::size_t right_len = p3 - p2;
	std::size_t l_idx = 0;
	std::size_t r_idx = 0;
	std::deque<unsigned int>	l_deq;
	std::deque<unsigned int>	r_deq;
	l_deq.insert(l_deq.begin(), this->seq_deque_.begin() + p1
							  , this->seq_deque_.begin() + p1 + left_mid_len);
	r_deq.insert(r_deq.begin(), this->seq_deque_.begin() + p2 + 1
							  , this->seq_deque_.begin() + p2 + 1 + right_len);
	for (std::size_t i = p1; i < p3 + 1; ++i) {
		if (r_idx == right_len) {					// 오른쪽 다 채웠으면
			this->seq_deque_.at(i) = l_deq.at(l_idx++);
		} else if (l_idx == left_mid_len) {			// 왼쪽 다 채웠으면
			this->seq_deque_.at(i) = r_deq.at(r_idx++);
		} else if (r_deq.at(r_idx) > l_deq.at(l_idx)) {
			this->seq_deque_.at(i) = l_deq.at(l_idx++);
		} else {// r_deq.at(r_idx) <= l_deq[l_idx])
			this->seq_deque_.at(i) = r_deq.at(r_idx++);
		}
		// printContainer(this->seq_deque_);
	}
}

void	PmergeMe::mergeInsertionSortDeque(std::size_t p1, std::size_t p3) {
	if (p3 - p1 < K) {
		InsertionSortDeque(p1, p3);
		return;
	}
	std::size_t p2 = (p1 + p3) / 2; // mean value
	mergeInsertionSortDeque(p1, p2);
	mergeInsertionSortDeque(p2 + 1, p3);
	mergePartDeque(p1, p2, p3);
}

void	PmergeMe::pushDataDeque(const std::string str_array[]) {
	for (std::size_t i = 0; i < this->n_element; ++i) {
		std::stringstream	ss(str_array[i]);
		unsigned int		num;
		ss >> num;
		num == 0 ? throw InvaildInput() : false;
		this->seq_deque_.push_back(num);
	}
}

void	PmergeMe::sortSequnceDeque(const std::string str_array[]) {
	pushDataDeque(str_array);
	mergeInsertionSortDeque(0, this->seq_deque_.size() - 1);
}

void	PmergeMe::InsertionSortVector(std::size_t p1, std::size_t p2) {
	std::size_t  j;
	unsigned int key;
	for (std::size_t i = p1; i < p2; ++i) {
		key = this->seq_vector_.at(i + 1);
		for (j = i + 1
			; j > p1 && this->seq_vector_.at(j - 1) > key; --j) {
		  this->seq_vector_.at(j) = this->seq_vector_.at(j - 1);
		}
		this->seq_vector_.at(j) = key;
	}
}

void	PmergeMe::mergePartVector(std::size_t p1, std::size_t p2, std::size_t p3) {
	const std::size_t left_mid_len = p2 - p1 + 1;
	const std::size_t right_len = p3 - p2;
	std::size_t l_idx = 0;
	std::size_t r_idx = 0;
	std::deque<unsigned int>	l_vec;
	std::deque<unsigned int>	r_vec;
	l_vec.insert(l_vec.begin(), this->seq_vector_.begin() + p1
							  , this->seq_vector_.begin() + p1 + left_mid_len);
	r_vec.insert(r_vec.begin(), this->seq_vector_.begin() + p2 + 1
							  , this->seq_vector_.begin() + p2 + 1 + right_len);
	for (std::size_t i = p1; i < p3 + 1; ++i) {
		if (r_idx == right_len) {	// 오른쪽 다 채웠으면
			this->seq_vector_.at(i) = l_vec.at(l_idx++);
		} else if (l_idx == left_mid_len) { // 왼쪽 다 채웠으면
			this->seq_vector_.at(i) = r_vec.at(r_idx++);
		} else if (r_vec.at(r_idx) > l_vec.at(l_idx)) {
			this->seq_vector_.at(i) = l_vec.at(l_idx++);
		} else {	// r_vec.at(r_idx) <= l_vec[l_idx])
			this->seq_vector_.at(i) = r_vec.at(r_idx++);
		}
	}
}

void	PmergeMe::mergeInsertionSortVector(std::size_t p1, std::size_t p3) {
	if (p3 - p1 <= K) {
		InsertionSortVector(p1, p3);
		return;
	}
	std::size_t p2 = (p1 + p3) / 2; // mean value
	mergeInsertionSortVector(p1, p2);
	mergeInsertionSortVector(p2 + 1, p3);
	mergePartVector(p1, p2, p3);
}

void	PmergeMe::pushDataVector(const std::string str_array[]) {
	for (std::size_t i(0); i < this->n_element; ++i) {
		std::stringstream	ss(str_array[i]);
		unsigned int		num;
		ss >> num;
		num == 0 ? throw InvaildInput() : false;
		this->seq_vector_.push_back(num);
	}
}

void	PmergeMe::sortSequnceVector(const std::string str_array[]) {
	pushDataVector(str_array);
	mergeInsertionSortVector(0, this->seq_vector_.size() - 1);
}

const char*	PmergeMe::InvaildInput::what(void) const throw() {
	return "Error";
}
