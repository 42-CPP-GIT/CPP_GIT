
// ref. https://blog.hexabrain.net/175

#include <iostream>

using namespace std;

class Parent {
	public:
		virtual void func() = 0;
		// 함수 포인터라고 생각하면 됨
		// virtual 4byte 적재가 되는데, 여러개 함수들을 관리할 수 있게 됨
		// issue 확인
};

class Child : public Parent {
	public:
		virtual void func() {
			cout << "자식 클래스의 func 함수 호출!" << endl;
		}
};

int main()
{
	// Parent P;		//<- 컴파일 에러

	Parent*	P = new Child;
	P->func();

	return 0;
}
