
// ref. https://blog.hexabrain.net/175

#include <iostream>

using namespace std;

class Parent {
	public:
		virtual void func() {
			cout << "부모 클래스의 func 함수 호출!" << endl;
		}
};

class Child : public Parent {
	public:
		virtual void func() {
			cout << "자식 클래스의 func 함수 호출!" << endl;
		}
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

	return 0;
}

