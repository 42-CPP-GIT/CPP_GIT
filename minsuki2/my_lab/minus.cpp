#include <iostream>

int main(void) {
	int a = INT_MAX - 1;
	int b = 2;

	//a + b : + 가 문제
	//a - b : - 가 문제
	if (a > 0 && b > 0 && INT_MAX - a < b) {
		std::cout << "Overflow" << std::endl; return 0;
	}
	else if (a < 0 && b > 0 && (a - INT_MIN < b)) {
		std::cout << "Overflow" << std::endl; return 0;
	}
	std::cout << a + b << std::endl;
	return 0;
}
