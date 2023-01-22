#include "Data.hpp"
#include "color.h"

uintptr_t serialize(Data* ptr) {
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return(reinterpret_cast<Data *>(raw));
}

int main(void) {
	Data	prev("Here!");
	Data*	next;
	uintptr_t ptr(0);

	std::cout << BOLDCYAN << "--- 초기 세팅 ---"
			  << RESET << std::endl;
	std::cout << "prev name    : " << prev.name_ << std::endl;
	std::cout << "prev address : " << &prev << std::endl;
	std::cout << "next address : " << next << std::endl;
	std::cout << "ptr          : " << "0x" << std::hex << ptr << std::endl;

	std::cout << BOLDGREEN << "--- serialize ---"
			  << RESET << std::endl;
	ptr = serialize(&prev);
	std::cout << "prev address : " << &prev << std::endl;
	std::cout << "next pointer : " << next << std::endl;
	std::cout << "ptr          : " << "0x" << std::hex << ptr << std::endl;

	std::cout << BOLDRED << "--- deserialize ---"
			  << RESET << std::endl;
	next = deserialize(ptr);
	std::cout << "prev address : " << &prev << std::endl;
	std::cout << "next address : " << next << std::endl;
	std::cout << "ptr          : " << "0x" << std::hex << ptr << std::endl;


	std::cout << BOLDWHITE << "--- check Data inside ---"
			  << RESET << std::endl;
	std::cout << "prev name    : " << prev.name_ << std::endl;
	std::cout << "next name    : " << next->name_ << std::endl;

	return (0);
}
/*
 *
구조가 있는 객체의 내용물을 바이트 배열로 저장하는 것을 직렬화(Serialization)이라고 하고, 반대로 바이트 배열로부터 내용물을 읽어와 객체에 채우는 것을 역직렬화(Deserialization)라고 합니다.

메모리안의 어떠한 (추상적) 데이터구조를 연속된 bit 로 외부에 보내기위해 정렬하는것.

그렇다면 이 문제에서는 string, int, string 구조체의 직렬화를 위해 몇 바이트 배열을 만들어야되냐가 문제인데, 총 52바이트(24 + 8 + 24) 인 것이다.

*/

/*

임의의 포인터 타입간의 형변환에 사용된다.

포인터 -> 포인터, 포인터 -> 일반변수, 일반변수 -> 포인터
정수형을 포인터로 바꿀 수도 있다.

즉, 일반적으로 허용하지 않는 위험한 형 변환을 (무조건적인 형 변환) 할 때 사용한다.

만약 int * -> char -> int * 로 이뤄지는 형변환이 있을 때, 주소값이 파괴되어 결국 nullptr을 가르키게 된다.
char형은 1바이트 크기여서 주소 값을 다 표현하지 못하기 때문이다.
즉, 데이터를 옮기는 과정에서 dump가 되버려 원본 데이터가 파괴될 위험이 있다.
(void *)로도 전달이 가능하기 때문에 특수한 경우에 쓰인다.

*/

/*네트워크에서 정보를 보낼 때 stream으로 보내야 하는데, 당연히 이건 기본 자료형으로만 보낼 수 있다.
 *
 *
 * 따라서 사용 중인 구조체나 클래스의 객체나 포인터의 정보를 보내기 위해서는 해당 정보를 기본 자료형으로 변환해줘야 하는데, 이를 직렬화라고 한다.

 물론 위와 같은 작업으로는 네트워크 전송에는 택도 없지만, 객체를 네트워크에 보낼 수 있는 값으로 변환하고
 그걸 받아서 다시 데이터로 만드는 작업을 해본다고 생각하면 될 것 같다.
 */
