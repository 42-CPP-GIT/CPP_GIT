#include "RPN.hpp"

/*
 * 1. 기호 앞에 숫자가 2개보다 많아야 함
 * ex) 1 + 1	=> Error!
 *
 * 2. 부호 개수가 서로 하나 차이가 나야함
 * ex) 11++		=> Error!
 */

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	const std::string& eqn(argv[1]);
	if (eqn.empty()) {
		std::cout << "Error(emtpy)" <<std::endl;
		return 1;
	}
	try {
		RPN		rpn(eqn);
		std::cout << rpn.calculate() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	} catch (const std::out_of_range& o) {
		std::cout << o.what() << std::endl;
	}
	return 0;
}

