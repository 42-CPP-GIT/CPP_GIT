
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
	} else if (argc != 2) {
		std::cout << "Error: so many files." << std::endl;
		return 1;
	}

	const std::string&	data_csv_path(PATH);
	const std::string& file_name(argv[1]);

	try {
		BitcoinExchange		bitco(data_csv_path);
		// checkMap(BitcoinExchange::getDatabase());
		bitco.calculateInput(file_name);

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}






	return 0;
}
