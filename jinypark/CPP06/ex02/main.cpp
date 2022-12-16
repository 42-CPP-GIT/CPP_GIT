#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"
#include <iomanip>
#include <ctime>

void nothing(void *) {}

Base * generate(void)
{
	int i = rand() % 3;

	switch (i)
	{
	case 0:
		return (new BaseA());
	case 1:
		return (new BaseB());
	default:
		return (new BaseC());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<BaseA *>(p))
		std::cout << "Class type is BaseA\n";
	else if (dynamic_cast<BaseB *>(p))
		std::cout << "Class type is BaseB\n";
	else if (dynamic_cast<BaseC *>(p))
		std::cout << "Class type is BaseC\n";
	else
		std::cout << "Class type is Base\n";
}

void identify(Base& p)
{
	try
	{
		BaseA& newA = dynamic_cast<BaseA &>(p);
		nothing(&newA);
		std::cout << "Class type is BaseA\n";
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		BaseB& newB = dynamic_cast<BaseB &>(p);
		nothing(&newB);
		std::cout << "Class type is BaseB\n";
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		BaseC& newC = dynamic_cast<BaseC &>(p);
		nothing(&newC);
		std::cout << "Class type is BaseC\n";
		return ;
	}
	catch(const std::exception& e) {
		std::cout << "Class type is Base\n";
	}

}

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
	{
		Base* base = generate();
		std::cout << "-----[test " << i + 1 << " start]-----\n";
		identify(base);
		identify(*base);
		std::cout << "------[test " << i + 1 << " end]------\n";
		delete base;
	}
	Base* base = new Base();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}