
// ref. https://blog.hexabrain.net/175

#include <iostream>

using namespace std;

class Parent {
	public:
		void func() { cout << "부모 클래스의 func 함수 호출!" << endl; }
};

class Child : public Parent {
	public:
		void func() { cout << "자식 클래스의 func 함수 호출!" << endl; }
};

int main()
{
	Parent P;
	Child C;

	Parent* ptr;

	ptr=&P;
	ptr->func();		// Parent 함수 출력

	ptr=&C;
	ptr->func();		// Parent 함수 출력
	//  C++ 컴파일러가 실제로 가리키는 객체의 자료형을 기준으로 하는게 아닌, 포인터 변수의 자료형을 기준으로 판단하기 때문
	//  => virtual 키워드로 해결

	return 0;
}
