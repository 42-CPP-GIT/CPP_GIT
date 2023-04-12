
#include "BitcoinExchange.hpp"

// template<typename T>
// void	checkMap(const T& cur_map) {
//     for (typename T::const_iterator it(cur_map.begin())
//         ; it != cur_map.end(); ++it) {
//         std::cout << it->first << "\t" << std::setprecision(10) << it->second << std::endl;
//     }
// }

int main(int argc, char *argv[]) {
	/* argc 2, 3 제외 모두 차단 */
	if (argc < 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	} else if (argc > 3) {
		std::cout << "Error: so many files." << std::endl;
		return 1;
	}

	const std::string&	origin_data_csv(BitcoinExchange::getPath() + "data.csv");
	const char*			cur_data_csv = (argc == 2) ? origin_data_csv.c_str() : argv[2];

	/* ifstream c++98에서는 const char*을 parameter으로 받음 */
	std::ifstream	data_file(cur_data_csv);
	if (data_file.fail()) {
		std::cout << "Error: Unable to open file" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange		bitco(data_file);
		bitco.calculateInput(argv[1]);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} catch (const std::string& s) {
		std::cout << s << std::endl;
	}
	data_file.close();
	return 0;
}
