
#include <iostream>
#include <cmath>


static void	_checkAns(float val, const char name) {

	std::cout << '<' << name << '>' << std::endl;

	std::cout << "1 : "
			  << std::fabs(val) - std::floor(std::fabs(val)) << std::endl;

	std::cout << "2 : "
			  << std::fabs(val) - std::abs(static_cast<int>(val)) << std::endl;

	std::cout << "3 : "
			  << std::fabs(val) - std::abs(val) << std::endl;

	std::cout << std::endl << std::endl;
}

int main(void) {
	float a(4.1); _checkAns(a, 'a');
	float b(4.0001); _checkAns(b, 'b');
	float c(4.00001); _checkAns(c, 'c');
	float d(4.000001); _checkAns(d, 'd');
	float e(4.0000001); _checkAns(e, 'e');
	float f(4.00000001); _checkAns(f, 'f');

	float g(0.0000001);
	float h(0.00000001);
	float i(0.000000001);



	0 < g ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;

	0 < h ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;

	std::cout << -0 << std::endl;
	std::cout << -0.0f << std::endl;
	std::cout << -0.0 << std::endl;

	return 0;
}

