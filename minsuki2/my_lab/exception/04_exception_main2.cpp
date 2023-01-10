#include <exception>
#include <iostream>

class CustomException :	public std::exception {
	public:
		const char* what(void) const throw() { return ("CustomException"); }
};

int main(void)
{
	while (true) {
		try {
			std::string		key;
			while (true) {
				std::cin >> key;
				if (key == "cause")
					throw (CustomException());
				if (key == "int")
				  throw (1);
				if (key == "double")
					throw (0.5);
			}
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;

		/* 1. int double Caught */

		// } catch (int& i) {
		//     std::cerr << "Int Caught" << std::endl;
		// } catch (double& d) {
		//     std::cerr << "Double Caught" << std::endl;

		/* 2. Numeric Caught */

		} catch (...) {
			std::cerr << "Numeric Caught" << std::endl;
		}

		std::cout << "Program End Normally" << std::endl;
	}
	return (0);
}
