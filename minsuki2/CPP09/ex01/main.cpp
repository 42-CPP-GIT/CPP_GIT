#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	const std::string& eqn(argv[1]);
	try {
		RPN		rpn(eqn);
		std::cout << rpn.calculate() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}


}

