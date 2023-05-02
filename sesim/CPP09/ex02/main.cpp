// #include "PmergeMe.hpp"
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe	tmp((argc - 1), &(argv[1]));
		tmp.ftSort();
		tmp.printRes();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}