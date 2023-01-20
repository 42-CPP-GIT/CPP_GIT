
#include <iomanip>
#include "color.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	int	pick(std::rand() % 3);

	if (pick == 0) { return new A(); }
	else if (pick == 1) { return new B(); }
	else { return new C(); }
}

void identify(Base* p)		// NULL 사용 가능
{
	std::cout << "identify pointer is ";
	dynamic_cast<A*>(p) != NULL ? std::cout << "A" : false; std::cout << ".";

	dynamic_cast<B*>(p) != NULL ? std::cout << "B" : false; std::cout << ".";

	dynamic_cast<C*>(p) != NULL ? std::cout << "C" : false; std::cout << std::endl;
}

void identify(Base& p)		// NULL 사용 불가
{
	std::cout << "identify reference is ";
	A testA; B testB; C testC;

	try {
		// A &testA = dynamic_cast<A&>(testB); static_cast<void>(testA);
		A &a = dynamic_cast<A&>(p); static_cast<void>(a);
		std::cout << "A";
	}
  	catch (std::exception&) { } std::cout << ".";


	try {
		// B &testB = dynamic_cast<B&>(testC); static_cast<void>(testB);
		B &b = dynamic_cast<B&>(p); static_cast<void>(b);
		std::cout << "B";
	}
  	catch (std::exception&) { } std::cout << ".";


	try {
		// C &testC = dynamic_cast<C&>(testA); static_cast<void>(testC);
		C &c = dynamic_cast<C&>(p); static_cast<void>(c);
		std::cout << "C";
	}
  	catch (std::exception&) { } std::cout << std::endl;
}



int main(void) {
	std::srand(time(NULL));

	std::cout << BOLDCYAN << "--- identify start ---"
			  << RESET << std::endl << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		Base* base = generate();
		std::cout << BOLDBLUE << "[ Iter : " << i + 1 << "]" 
				  << RESET << std::endl;
		identify(base);
		identify(*base);
		std::cout << BOLDMAGENTA << "-------------------------------------" 
				  << RESET << std::endl << std::endl;
		delete base;
	}

	std::cout << BOLDWHITE << "--- self parent identify start ---" 
			  << RESET << std::endl << std::endl;
	Base* base = new Base();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
