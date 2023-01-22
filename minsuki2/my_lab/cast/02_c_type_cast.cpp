
#include <iostream>

int	main(void) {
	const int num = 20;
	// int* ptr = (int*)&num;			// const 포인터 -> 강제로 포인터
	int* ptr = static_cast<int*>(&num);
	*ptr = -30;						// 말이 안됨

	std::cout << *ptr << std::endl;
	std::cout << num << std::endl;
}
