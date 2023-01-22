
#include <iostream>

class Parent { };

class Child : public Parent {};

int main(void) {
	Parent*	p1 = new Child();
	Child*	c1 = static_cast<Child *>(p1);
	// compile success!

	Parent*	p2 = new Parent();
	Child*	c2 = static_cast<Child *>(p2);
	// compile success! But, 기존 객체가 Parent라서 Child로 Type cast할 시 Child에 없는 멤버변수가 있을 수 있음.

	Child*	c3 = new Child();
	Parent* p3 = static_cast<Parent*>(c3);
	// compile success!

	return 0;
}
