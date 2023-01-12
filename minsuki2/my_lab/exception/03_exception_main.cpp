
#include <exception>
#include <iostream>

class CustomException :	public std::exception {
	public:
		const char* what(void) const throw() { return ("CustomException"); }
};

int main(void)
{
	try {
		std::string		key;
		while (true) {
			std::cin >> key;
			if (key == "cause")
				throw (CustomException());
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Program End Normally" << std::endl;
	return (0);
}

// Ref. https://bigpel66.oopy.io/library/42/inner-circle/16
