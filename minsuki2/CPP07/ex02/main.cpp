#include <iostream>
#include <Array.hpp>
#include <cstdlib>

#define MAX_VAL 1

// static void only_exit(void) {
	// system("leaks -q array");
// }

int main(int, char**)
{
	// std::atexit(only_exit);
	std::cout << BOLDBLUE << "--- PDF : *a print ---"
		<< RESET << std::endl;
	int* a = new int();
	std::cout << "*a = " << *a << std::endl << std::endl;
	delete a;

	std::cout << BOLDCYAN << "--- Subject : main.cpp ---"
		<< RESET << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
		const int i = -2;
        numbers[i] = 0;
		std::cout << numbers[i] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
	}

    try
    {
		const int i = MAX_VAL;
        numbers[i] = 0;
		std::cout << numbers[i] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

	std::cout << BOLDMAGENTA << std::endl << "--- self test : size() func ---"
			  << RESET << std::endl;
	std::cout << numbers.size() << std::endl << std::endl;
    delete[] mirror;
	// tpp 내부 array delete[] 필요 유추 가능
    return 0;
}
