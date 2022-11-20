#include "Fixed.hpp"
#include <bitset>

int	main(void)
{
	Fixed		a(10.24751f);
	// Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed const	b(4.96241f);

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max(a, b) << std::endl;
	std::cout << a + b << std::endl;

}
