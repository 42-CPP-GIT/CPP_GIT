#include <exception>
#include <iostream>

class CustomException :	public std::exception {
	public:
		const char* what(void) const throw() { return ("CustomException"); }
};

int main(void)
{
	CustomException		e;
	std::cout << e.what() << std::endl;
	return (0);
}
