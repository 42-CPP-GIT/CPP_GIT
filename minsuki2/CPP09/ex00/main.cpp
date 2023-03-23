
#include "BitcoinExchange.hpp"

template<typename T>
void	checkMap(const T& cur_map) {
	for (typename T::const_iterator it(cur_map.begin())
		; it != cur_map.end(); ++it) {
		std::cout << it->first << "\t" << std::setprecision(10) << it->second << std::endl;
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	} else if (argc > 3) {
		std::cout << "Error: so many files." << std::endl;
		return 1;
	}

	try {
		const std::string& file_name(argv[1]);
		if (argc == 2) {
			const std::string&	data_csv_path(PATH);
			BitcoinExchange		bitco(data_csv_path);
			bitco.calculateInput(file_name);
		}
		else if (argc == 3) {
			BitcoinExchange		bitco(argv[2]);
			bitco.calculateInput(file_name);
		}
		// checkMap(BitcoinExchange::getDatabase());

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
