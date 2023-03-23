#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>

const char*	PmergeMe::InvalidArgument::what() const throw()
{
	return ("Error");
}

int	PmergeMe::check_val(size_t nb, int pn)
{
	if (nb > 2147483647 && pn == 1)
		return (-1);
	else if (nb > 2147483648 && pn == -1)
		return (0);
	return ((int)nb * pn);
}

int	PmergeMe::ft_atoi(const char *str)
{
	unsigned int	i;
	size_t			res;
	int				pn;

	i = 0;
	res = 0;
	pn = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			pn *= -1;
		i++;
	}
	while (std::isdigit(str[i]) && *str)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (check_val(res, pn));
}

bool	PmergeMe::ArgumentCheckWithInit(const int& argc, char** argv)
{
	size_t	k;
	for (int i(0); i < argc; ++i)
	{
		k = 0;
		while (std::isspace(static_cast<int>(argv[i][k])))
			k++;
		if (argv[i][k] == '+')
			k++;
		while (std::isdigit(static_cast<int>(argv[i][k])))
			k++;
		if (k == std::strlen(argv[i]))
		{
			int	val = ft_atoi(argv[i]);
			if (val < 0)
				return (false);
			_sort_vec.push_back(val);
			_sort_deque.push_back(val);
			continue ;
		}
		return (false);
	}
	return (true);
}

PmergeMe::PmergeMe(const int& argc, char** argv)
: _ac(argc)
{
	if (!ArgumentCheckWithInit(argc, argv))
		throw InvalidArgument();
	std::cout << "Before:	"; 
	print_container(this->_sort_vec);
}

PmergeMe::~PmergeMe()
{

}

void	PmergeMe::ft_sort()
{
	clock_t	start = std::clock();
	mergeInsertionSort(this->_sort_vec.begin(), this->_sort_vec.end(), 32);
	clock_t	end = std::clock();
	this->_vector_time = static_cast<double>(end - start) / (double)1000;
	start = std::clock();
	mergeInsertionSort(this->_sort_deque.begin(), this->_sort_deque.end(), 32);
	end = std::clock();
	this->_deque_time = static_cast<double>(end - start) / (double)1000;
}

void	PmergeMe::print_res()
{
	std::cout << "After:	"; 
	print_container(this->_sort_deque);
	std::cout << "=======================\n";
	std::cout << ((std::is_sorted(_sort_vec.begin(), _sort_vec.end()) == true) ?  "Vec Sorted" : "Not sorted") << std::endl;
	std::cout << ((std::is_sorted(_sort_deque.begin(), _sort_deque.end()) == true) ? "Deque Sorted" : "Not sorted") << std::endl;
	std::cout << "=======================\n";
	std::cout << "Time to process a range of " << this->_ac << " elements with std::vector : " << this->_vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_ac << " elements with std::deque  : " << this->_deque_time << " us" << std::endl;
}
