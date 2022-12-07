#include "Fixed.hpp"
#include <bitset>

int	main(void)
{
	Fixed		a(10.24751f);
	Fixed		c(8368600.0f);
	// Fixed		c(607.0f);
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	// Fixed const	b(4.96241f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << a + b << std::endl;
	std::cout << c * 2.0f << std::endl;
	Fixed	tmp1(36000);
	Fixed	tmp2(250);
	Fixed	tmp3(36250);

	std::cout << "==============================\n";
	std::cout << tmp1 / 7 << std::endl;
	std::cout << tmp2 / 7 << std::endl;
	std::cout << (tmp2 / 7) + (tmp1 / 7) << std::endl;
	std::cout << tmp3 / 7 << std::endl;
	std::cout << c / 2 << std::endl;

}
