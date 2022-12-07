#include <iostream>

int	main(int argc, char **argv)
{
	int	a = 0x7F800000;
	a |= 1 << 31;
	float	b;
	int		c;

	std::memcpy(&b, &a, sizeof(float));
	std::memcpy(&c, &b, sizeof(int));

	std::cout << std::bitset<32>(a) << std::endl;
	std::cout << &b << std::endl;
	std::cout << std::hex << c << std::dec << std::endl;
	if (isinf(b))
		std::cout << "b is inf" <<std::endl;
	if (isnan(b))
		std::cout << "b is nan" <<std::endl;

	int	div(3);
	int	mod = (1280 % div) * 10;
	if (mod / div > div)
		std::cout << "over than 0.5" << std::endl; 
	else
		std::cout << "less than 0.5" << std::endl;
}