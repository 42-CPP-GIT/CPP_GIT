
#include <iostream>

class Parent { };

class Child : public Parent {};

int main(void) {
	Parent*	p1 = new Child();
	Child*	c1 = dynamic_cast<Child *>(p1);
	// Compile Failed...

	Parent*	p2 = new Parent();
	Child*	c2 = dynamic_cast<Child *>(p2);
	// Compile Failed...

	Child*	c3 = new Child();
	Parent* p3 = dynamic_cast<Parent*>(c3);
	// Compile success!
	// 포인터로 참조하기 위해 사용

	return 0;
}

/*상속관계에 있는 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환*/
