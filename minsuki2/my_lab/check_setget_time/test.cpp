
#include "Fixed.hpp"

int	main(void) {
	Fixed	a;

	// b = b;
	for (int i = 0; i < 1000000000; i++) {
		a.count(i);
		// std::cout << i << std::endl;
	}
	return 0;
}

