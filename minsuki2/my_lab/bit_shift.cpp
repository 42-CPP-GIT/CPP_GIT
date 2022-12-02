
#include <iostream>

int main(void) {
	int a = INT_MIN;
	unsigned int b = static_cast<unsigned int>INT_MIN >> 4;
	int c = -1;

	std::cout << std::bitset<32>(a) << std::endl;
	std::cout << std::bitset<32>(a >> 1) << std::endl;
	std::cout << std::bitset<32>(b >> 1) << std::endl;
	std::cout << std::bitset<32>(b << c) << std::endl;

	return 0;

}


/* 참고자료
https://better-today.tistory.com/2
*/
