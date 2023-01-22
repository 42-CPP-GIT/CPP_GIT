
#include <iostream>

using namespace std;

class A {
	virtual void	show() const {
		cout << "A class" << endl;
	}
};

class B : public A {
	void	show() const {
		cout << "B class" << endl;
	}
};

int	main(void) {

	{
		A* a_ptr = new B();
		B* b_ptr = dynamic_cast<B*>(a_ptr);

		b_ptr != NULL ? cout << "성공" : cout << "실패";
		cout << endl;
	}

	{
		A* a_ptr = new A();
		B* b_ptr = dynamic_cast<B*>(a_ptr);


		b_ptr != NULL ? cout << "성공" : cout << "실패";
		cout << endl;

	}

	return 0;

}
/* 컴파일 시간이 아닌 
 * 런타임에 안정성을 검사하도록 컴파일러가 바이너리 코드를 생성*/
