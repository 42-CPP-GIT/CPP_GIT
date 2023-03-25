#include "PmergeMe.hpp"
#include <cstddef>
#include <iterator>
#include <utility>

const char*	PmergeMe::InvalidArgument::what() const throw()
{
	return ("Error");
}

int	PmergeMe::_checkVal(size_t nb, int pn)
{
	if (nb > 2147483647 && pn == 1)
		return (-1);
	else if (nb > 2147483648 && pn == -1)
		return (0);
	return ((int)nb * pn);
}

int	PmergeMe::_ftAtoi(const char *str)
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
	return (_checkVal(res, pn));
}

bool	PmergeMe::_argumentCheckWithInit(const int& argc, char** argv)
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
			int	val = _ftAtoi(argv[i]);
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
: _ac(argc), _min_run(0)
{
	if (!_argumentCheckWithInit(argc, argv))
		throw InvalidArgument();
	std::cout << "Before:	"; 
	_printContainer(this->_sort_vec);
}

PmergeMe::~PmergeMe()
{

}

/**
* Timsort with Iterator
*/

int	PmergeMe::_calMinRunLength(int size, const int min)
{
	int	run(0);
	while (size >= min)
	{
		run |= size & 1;
		size >>= 1;
	}
	return (run + size);
}

void	PmergeMe::_InsertionSortWithIter(const vec_int::iterator& left, const vec_int::iterator& right)
{
	int	key;
	vec_int::iterator j;
	for (vec_int::iterator it = left + 1; it != right; ++it)
	{
		key = *it;
		j = it - 1;
		while (j >= left && *j > key)
		{
			*(j + 1) = *j;
			j--;
		}
		*(j + 1) = key;
	}
}

void	PmergeMe::_timMergeWithIter(const vec_int::iterator& begin, const vec_int::iterator& mid, const vec_int::iterator& end)
{
	std::vector<int>	tmp;

	vec_int::iterator	left = begin;
	vec_int::iterator	right = mid;

	while (left != mid && right != end)
	{
		if (*left <= *right)
		{
			tmp.push_back(*left);
			++left;
		}
		else
		{
			tmp.push_back(*right);
			++right;
		}
	}

	while (left != mid)
	{
		tmp.push_back(*left);
		++left;
	}
	while (right != end)
	{
		tmp.push_back(*right);
		right++;
	}
	std::copy(tmp.begin(), tmp.end(), begin);
}

void	PmergeMe::_timSortwithIter(const vec_int::iterator& begin, const vec_int::iterator& end)
{
	int	size = std::distance(begin, end);
	// if (size <= 32)
	if (size <= _calMinRunLength(size, 32))
	{
		_InsertionSortWithIter(begin, end);
		return ;
	}
	const vec_int::iterator	mid = begin + std::distance(begin, end) / 2;
	_timSortwithIter(begin, mid);
	_timSortwithIter(mid, end);
	_timMergeWithIter(begin, mid, end);
}

/**
* Timsort with vector
*/

void	PmergeMe::_timInsertionSortWithRef(vec_int& arr, const int& left, const int& right)
{
	int	key;
	int	j;
	for (int i = left + 1; i <= right; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void	PmergeMe::_timMergeWithRef(vec_int& arr, const int& left, const int& mid, const int& right)
{
	int	i(left);
	int	j(mid + 1);
	vec_int	tmp(right - left + 1);

	for (size_t k(0); k < tmp.size(); ++k)
	{
		if (i > mid)
		{
			tmp[k] = arr[j++];
		}
		else if (j > right)
		{
			tmp[k] = arr[i++];
		}
		else if (arr[i] <= arr[j])
		{
			tmp[k] = arr[i++];
		}
		else
		{
			tmp[k] = arr[j++]; 
		}
	}
	std::copy(tmp.begin(), tmp.end(), arr.begin() + left);
}

void	PmergeMe::_timSortWithRef(vec_int& arr)
{
	// const int	size = arr.size();
	// const int	run = _calMinRunLength(size, 32);

	// for (int i(0); i < size; i += run)
	// {
	// 	_timInsertionSortWithRef(arr, i, std::min<int>(i + run - 1, size - 1));
	// }

	// int	mid;
	// int	right;
	// for (int n(run); n < size; n *= 2)
	// {
	// 	for (int left(0); left < size; left += 2 * n)
	// 	{
	// 		mid = left + n - 1;
	// 		right = std::min<int>(left + 2 * n - 1, size - 1);
	// 		_timMergeWithRef(arr, left, mid, right);
	// 	}
	// }

	const int	size = arr.size();
	const int	run = _calMinRunLength(size, 32);
	// const int	run = 32;

	for (int i = 0; i < size; i += run)
		_timInsertionSortWithRef(arr, i, std::min(i + run - 1, size - 1));

	int	mid;
	int	right;
	for (int n = run; n < size; n *= 2)
	{
		for (int left = 0; left < size; left += 2 * n)
		{
			mid = left + n - 1;
			right = std::min(left + 2 * n - 1, size - 1);
			_timMergeWithRef(arr, left, mid, right);
		}
	}
}


/**
 * Ford Johnson Sort with iterator
 */

void	PmergeMe::_fordMergeWithIter(const vec_int::iterator& begin, const vec_int::iterator& mid, const vec_int::iterator& end)
{
	vec_int::iterator	left = begin;
	vec_int::iterator	right = mid + 1;
	vec_int				tmp;

	while (left <= mid && right <= end)
	{
		if (*left < *right)
		{
			tmp.push_back(*left);
			++left;
		}
		else
		{
			tmp.push_back(*right);
			++right;
		}
	}
	while (left <= mid)
	{
		tmp.push_back(*left);
		++left;
	}
	while (right <= end)
	{
		tmp.push_back(*right);
		++right;
	}
	for (size_t	i(0); i < tmp.size(); ++i)
	{
		*(begin + i) = tmp[i];
	}
}

void	PmergeMe::_fordInsertionSortWithIter(const vec_int::iterator& left, const vec_int::iterator& right)
{
	int	key;
	vec_int::iterator	j;
    for (vec_int::iterator it = left + 1; it < right; ++it)
	{
		key = *it;
		j = it - 1;
		while (j >= left && *j > key)
		{
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = key;
	}
}

void	PmergeMe::_fordJohnsonSortWithIter(const vec_int::iterator& begin, const vec_int::iterator& end)
{
	vec_int::iterator	it = begin;
	vec_pair			pairs;

	// Divide the array into pairs
	for (; it < end - 1; it += 2)
	{
		if (*it > *(it + 1))
		{
			pairs.push_back(std::make_pair(*(it + 1), *it));
		}
		else
		{
			pairs.push_back(std::make_pair(*it, *(it + 1)));
		}
	}

	// Handle the last element if the size is odd
	if (it == end - 1)
	{
		pairs.push_back(std::make_pair(*(end - 1), *(end - 1)));
	}

	// Sort the pairs
	std::pair<int, int>	tmp;
	size_t				j;
	for (size_t gap = pairs.size() / 2; gap > 0; gap /= 2)
	{
		for (size_t i = gap; i < pairs.size(); ++i)
		{
			tmp = pairs[i];
			for (j = i; j >= gap && tmp < pairs[j - gap]; j -= gap)
			{
				pairs[j] = pairs[j - gap];
			}
			pairs[j] = tmp;
		}
	}

	// Merge the pairs
	int	left;
	int	right;
	while (pairs.size() > 1)
	{
		tmp = pairs.back();
		pairs.pop_back();
		left = std::lower_bound(begin, end, tmp.first) - begin;
		right = std::upper_bound(begin, end, tmp.second) - begin - 1;
		_fordMergeWithIter(begin + left, begin + (left + right) / 2, begin + right);
	}

	// Handle the last element if the size is odd
	int	last;
	if ((end - begin) % 2 == 1)
	{
		last = *(end - 1);
		for (it = end - 2; it >= begin && *it > last; --it)
		{
			*(it + 1) = *it;
		}
		*(it + 1) = last;
	}

	// Run insertion sort on remaining unsorted part
	_fordInsertionSortWithIter(begin, end);
}

/**
 Ford Johnson Algorithm with vector
 */
void	PmergeMe::_fordMergeWithRef(vec_int& arr, int left, int mid, int right)
{
	int i = left, j = mid + 1;
	vec_int tmp;

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			tmp.push_back(arr[i++]);
		} else {
			tmp.push_back(arr[j++]);
		}
	}
	while (i <= mid) tmp.push_back(arr[i++]);
	while (j <= right) tmp.push_back(arr[j++]);

	for (size_t k = 0; k < tmp.size(); ++k) {
		arr[left + k] = tmp[k];
	}
}

void	PmergeMe::_fordInsertionSortWithRef(vec_int& arr, int left, int right)
{
	int	key;
	int	j;
	for (int i = left + 1; i <= right; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void	PmergeMe::_fordJohnsonSortWithRef(vec_int& arr)
{
	std::vector<std::pair<int, int> > pairs;

	// Divide the array into pairs
	int i = 0, n = arr.size();
	for (; i < n - 1; i += 2) {
		if (arr[i] > arr[i+1]) {
			pairs.push_back(std::make_pair(arr[i+1], arr[i]));
		} else {
			pairs.push_back(std::make_pair(arr[i], arr[i+1]));
		}
	}

	// Handle the last element if the size is odd
	if (i == n - 1) {
		pairs.push_back(std::make_pair(arr[n-1], arr[n-1]));
	}

	// Sort the pairs
	for (size_t gap = pairs.size() / 2; gap > 0; gap /= 2) {
		for (size_t i = gap; i < pairs.size(); ++i) {
			std::pair<int, int> tmp = pairs[i];
			size_t j;
			for (j = i; j >= gap && tmp < pairs[j-gap]; j -= gap) {
				pairs[j] = pairs[j-gap];
			}
			pairs[j] = tmp;
		}
	}

	// Merge the pairs
	while (pairs.size() > 1) {
		std::pair<int, int> p = pairs.back();
		pairs.pop_back();
		int left = std::lower_bound(arr.begin(), arr.end(), p.first) - arr.begin();
		int right = std::upper_bound(arr.begin(), arr.end(), p.second) - arr.begin() - 1;
		_fordMergeWithRef(arr, left, (left + right) / 2, right);
	}

	// Handle the last element if the size is odd
	if (n % 2 == 1) {
		int last = arr[n-1];
		int i;
		for (i = n-2; i >= 0 && arr[i] > last; --i) {
			arr[i+1] = arr[i];
		}
		arr[i+1] = last;
	}

	// Run insertion sort on remaining unsorted part
	_fordInsertionSortWithRef(arr, 0, n-1);
}




/**
 * Print Containers Functions
 */

void	PmergeMe::_printContainer(const vec_int& vec)
{
	vec_int::const_iterator	it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::_printContainer(const deq_int& vec)
{
	deq_int::const_iterator	it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::ftSort()
{
	clock_t	start = std::clock();
	// _timSortwithIter(this->_sort_vec.begin(), this->_sort_vec.end());
	_timSortWithRef(this->_sort_vec);
	// _fordJohnsonSortWithIter(this->_sort_vec.begin(), this->_sort_vec.end());
	// _fordJohnsonSortWithRef(this->_sort_vec);
	// std::sort(this->_sort_vec.begin(), this->_sort_vec.end());
	clock_t	end = std::clock();
	this->_vector_time = static_cast<double>(end - start) / (double)1000;
	// start = std::clock();
	// mergeInsertionSort(this->_sort_deque.begin(), this->_sort_deque.end(), 32);
	// end = std::clock();
	// this->_deque_time = static_cast<double>(end - start) / (double)1000;
}

void	PmergeMe::printRes()
{
	std::cout << "After:	"; 
	_printContainer(this->_sort_vec);
	/**
	* for debug
	*/
	std::cout << "=======================\n";
	std::cout << ((std::is_sorted(_sort_vec.begin(), _sort_vec.end()) == true) ?  "Vec Sorted" : "Not sorted") << std::endl;
	std::cout << ((std::is_sorted(_sort_deque.begin(), _sort_deque.end()) == true) ? "Deque Sorted" : "Not sorted") << std::endl;
	std::cout << "=======================\n";
	/*
	*
	*/
	std::cout << "Time to process a range of " << this->_ac << " elements with std::vector : " << this->_vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_ac << " elements with std::deque  : " << this->_deque_time << " us" << std::endl;
}
