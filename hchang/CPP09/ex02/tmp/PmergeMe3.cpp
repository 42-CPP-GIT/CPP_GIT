#include "PmergeMe.hpp"

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
: _run_stack_size(0), _ac(argc), _min_run(0)
{
	if (!_argumentCheckWithInit(argc, argv))
		throw InvalidArgument();
	std::cout << "Before:	"; 
	_printContainer(this->_sortedVec);
}

PmergeMe::~PmergeMe()
{

}

/**
*  Calculate the Run Length
*/

int	PmergeMe::_calMinRunLength(int size)
{
	int	run(0);
	while (size >= 64)
	{
		run |= size & 1;
		size >>= 1;
	}
	return (run + size);
}

/**
 * ========================== Vector Tim Sort ========================== 
 */

void	PmergeMe::_reverse(vec_int& arr, int left, int right)
{
	int	tmp;
	while (left < right)
	{
		tmp = arr[left];
		arr[left++] = arr[right];
		arr[right--] = tmp;
	}
}

int	PmergeMe::_getAscending(vec_int& arr, const int& left, const int& right)
{
	int	ordered_pos = left + 1;
	if (ordered_pos == right)
	{
		return (1);
	}

	if (arr[left] <= arr[ordered_pos])
	{
		while (ordered_pos < right && arr[ordered_pos - 1] <= arr[ordered_pos])
		{
			ordered_pos++;
		}
	}
	else
	{
		while (ordered_pos < right && arr[ordered_pos - 1] > arr[ordered_pos])
		{
			ordered_pos++;
		}
		_reverse(arr, left, ordered_pos - 1);
	}
	return (ordered_pos - left);
}

int	PmergeMe::_binarySearch(const vec_int& arr, const int& key, int left, int right)
{
	int	mid;

	while (left < right)
	{
		mid = left + ((right - left) / 2);
		if (key < arr[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return (left);
}

void	PmergeMe::_BinaryInsertionSort(vec_int& arr, const int& left, const int& right, int start)
{
	if (left == start)
	{
		start++;
	}

	int	key;
	int	binary_pos;
	int	insert_pos;
	for (; start < right; ++start)
	{
		key = arr[start];
		binary_pos = _binarySearch(arr, key, left, start);

		insert_pos = start - 1;
		while (insert_pos >= binary_pos)
		{
			arr[insert_pos + 1] = arr[insert_pos];
			--insert_pos;
		}
		arr[binary_pos] = key;
	}
}

int	PmergeMe::_gallopRight(vec_int& arr, const int& key, const int& b_pos, const int& a_len)
{
	int	left(0);
	int	right(1);

	if (key < arr[b_pos])
	{
		return (0);
	}
	else
	{
		while (right < a_len && arr[b_pos + right] <= key)
		{
			left = right;
			right = (right << 1) + 1;

			if (right <= 0)
			{
				right = a_len;
			}
		}
		if (right > a_len)
		{
			right = a_len;
		}
	}

	++left;

	int	mid;
	while (left < right)
	{
		mid = left + ((right - left) >> 1);

		if (key < arr[b_pos + mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return (right);
}

int	PmergeMe::_gallopLeft(vec_int& arr, const int& key, const int& pos, const int& b_len)
{
	int	left(0);
	int	right(1);

	if (key > arr[pos + b_len - 1])
	{
		return (b_len);
	}
	else
	{
		const int	start_pos = pos + b_len -1;

		while (right < b_len && key <= arr[start_pos - right])
		{
			left = right;
			right = (right << 1) + 1;

			if (right <= 0)
			{
				right = b_len;
			}
		}
		if (right > b_len)
		{
			right = b_len;
		}

		int	tmp = left;
		left = b_len - 1 - right;
		right = b_len - 1 - tmp;
	}

	++left;
	int	mid;
	while (left < right)
	{
		mid = left + ((right - left) >> 1);

		if (key <= arr[pos + mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return right;
}

void	PmergeMe::_mergeLeft(vec_int& arr, const int& start1, const int& len1, const int& start2, const int& len2)
{
	vec_int	tmp(len1);
	for (int i(0); i < len1; ++i)
	{
		tmp.at(i) = arr.at(start1 + i);
	}

	int	insert_idx = start1;
	int	run_b_idx = start2;
	int	tmp_idx = 0;

	int left_run_len = len1;
	int	right_run_len = len2;

	while (left_run_len != 0 && right_run_len != 0)
	{
		if (arr[run_b_idx] < tmp[tmp_idx])
		{
			arr[insert_idx++] = arr[run_b_idx++];
			right_run_len--;
		}
		else
		{
			arr[insert_idx++] = tmp[tmp_idx++];
			left_run_len--;
		}
	}
	if (left_run_len != 0)
	{
		for (int i(0); i < left_run_len; ++i)
		{
			arr[insert_idx + i] = tmp[tmp_idx + i];
		}
	}
	else
	{
		for (int i(0); i < right_run_len; ++i)
		{
			arr[insert_idx + i] = arr[run_b_idx + i];
		}
	}
}

void	PmergeMe::_mergeRight(vec_int& arr, const int& start1, const int& len1, const int& start2, const int& len2)
{
	vec_int	tmp(len2);
	for (int i(0); i < len2; ++i)
	{
		tmp.at(i) = arr.at(start2 + i);
	}

	int	insert_idx = start2 + len2 - 1;
	int run_a_idx = start1 + len1 - 1;
	int	tmp_idx = len2 - 1;

	int	left_run_len(len1);
	int right_run_len(len2);

	while (left_run_len != 0 && right_run_len != 0)
	{
		if (arr[run_a_idx] > tmp[tmp_idx])
		{
			arr[insert_idx--] = arr[run_a_idx--];
			left_run_len--;
		}
		else
		{
			arr[insert_idx--] = tmp[tmp_idx--];
			right_run_len--;
		}
	}

	if (right_run_len != 0)
	{
		for (int i(0); i < right_run_len; ++i)
		{
			arr[start1 + i] = tmp[i];
		}
	}
}

void	PmergeMe::_merge(vec_int& arr, const int& idx)
{
	int	a_stack_pos = _run_base[idx];
	int a_stack_len = _run_len[idx];
	int	b_stack_pos = _run_base[idx + 1];
	int b_stack_len = _run_len[idx + 1];

	_run_len[idx] = a_stack_len + b_stack_len;

	if (idx == (_run_stack_size - 3))
	{
		_run_base[idx + 1] = _run_base[idx + 2];
		_run_len[idx + 1] = _run_len[idx + 2];
	}
	--_run_stack_size;

	int left(0);
	while (left < 7 && arr[a_stack_pos + left] <= arr[b_stack_pos])
	{
		left++;
	}
	if (arr[a_stack_pos + left] <= arr[b_stack_pos])
	{
		left = _gallopRight(arr, arr[b_stack_pos], a_stack_pos + left, a_stack_len - left);
	}

	if (a_stack_len == left)
	{
		return ;
	}
	a_stack_pos += left;
	a_stack_len -= left;

	int right(0);
	const int right_pos = b_stack_pos + b_stack_len - 1;
	const int left_key_pos = a_stack_pos + a_stack_len - 1;
	while (right < 7 && arr[left_key_pos] <= arr[right_pos - right])
	{
		right++;
	}
	if (arr[left_key_pos] <= arr[right_pos - right])
	{
		right = _gallopLeft(arr, arr[left_key_pos], b_stack_pos, b_stack_len - right);
	}
	else
	{
		right = b_stack_len - right;
	}

	if (right == 0)
	{
		return ;
	}

	b_stack_len = right;
	if (a_stack_len <= b_stack_len)
	{
		_mergeLeft(arr, a_stack_pos, a_stack_len, b_stack_pos, b_stack_len);
	}
	else
	{
		_mergeRight(arr, a_stack_pos, a_stack_len, b_stack_pos, b_stack_len);
	}
}

void	PmergeMe::_mergeForce(vec_int& arr)
{
	while (_run_stack_size > 1)
	{
		if (_run_stack_size > 2 && _run_len[_run_stack_size - 3] < _run_len[_run_stack_size - 1])
		{
			_merge(arr, _run_stack_size - 3);
		}
		else
		{
			_merge(arr, _run_stack_size - 2);
		}
	}
}

void	PmergeMe::_merge(vec_int& arr)
{
	while (_run_stack_size > 1)
	{
		if ((_run_stack_size > 2 && (_run_len[_run_stack_size - 3] <= _run_len[_run_stack_size - 2] + _run_len[_run_stack_size - 1]))\
			|| (_run_stack_size > 3 && (_run_len[_run_stack_size - 4] <= _run_len[_run_stack_size - 3] + _run_len[_run_stack_size - 2])))
		{
			if (_run_len[_run_stack_size - 3] < _run_len[_run_stack_size - 1])
			{
				_merge(arr, _run_stack_size - 3);
			}
			else
			{
				_merge(arr, _run_stack_size - 2);
			}
		}
		else if (_run_len[_run_stack_size - 2] <= _run_len[_run_stack_size - 1])
		{
			_merge(arr, _run_stack_size - 2);
		}
		else
		{
			break ;
		}
	}
}

void	PmergeMe::_pushRun(const int& runBase, const int& runLen)
{
	_run_base.at(_run_stack_size) = runBase;
	_run_len.at(_run_stack_size) = runLen;
	++_run_stack_size;
}

void	PmergeMe::_timSort(vec_int& arr)
{
	int	left(0);
	int right(arr.size());
	int	size(right);
	if (size < 2)
	{
		return ;
	}

	int	increaseRange;
	if (size < 32)
	{
		increaseRange = _getAscending(arr, left, right);
		_BinaryInsertionSort(arr, left, right, increaseRange);
		return ;
	}

	int	minRun = _calMinRunLength(size);
	do
	{
		increaseRange = _getAscending(arr, left, right);

		if (increaseRange < minRun)
		{
			const int	runLen = size < minRun ? size : minRun;

			_BinaryInsertionSort(arr, left, left + runLen, left + increaseRange);
			increaseRange = runLen;
		}
		_pushRun(left, increaseRange);
		_merge(arr);

		left += increaseRange;
		size -= increaseRange;
	}
	while (size != 0)
		;
	_mergeForce(arr);
}
/**
 * ========================== Deque Tim Sort ========================== 
 */

void	PmergeMe::_reverse(deq_int& arr, int left, int right)
{
	int	tmp;
	while (left < right)
	{
		tmp = arr[left];
		arr[left++] = arr[right];
		arr[right--] = tmp;
	}
}

int	PmergeMe::_getAscending(deq_int& arr, const int& left, const int& right)
{
	int	ordered_pos = left + 1;
	if (ordered_pos == right)
	{
		return (1);
	}

	if (arr[left] <= arr[ordered_pos])
	{
		while (ordered_pos < right && arr[ordered_pos - 1] <= arr[ordered_pos])
		{
			ordered_pos++;
		}
	}
	else
	{
		while (ordered_pos < right && arr[ordered_pos - 1] > arr[ordered_pos])
		{
			ordered_pos++;
		}
		_reverse(arr, left, ordered_pos - 1);
	}
	return (ordered_pos - left);
}

int	PmergeMe::_binarySearch(const deq_int& arr, const int& key, int left, int right)
{
	int	mid;

	while (left < right)
	{
		mid = left + ((right - left) / 2);
		if (key < arr[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return (left);
}

void	PmergeMe::_BinaryInsertionSort(deq_int& arr, const int& left, const int& right, int start)
{
	if (left == start)
	{
		start++;
	}

	int	key;
	int	binary_pos;
	int	insert_pos;
	for (; start < right; ++start)
	{
		key = arr[start];
		binary_pos = _binarySearch(arr, key, left, start);

		insert_pos = start - 1;
		while (insert_pos >= binary_pos)
		{
			arr[insert_pos + 1] = arr[insert_pos];
			--insert_pos;
		}
		arr[binary_pos] = key;
	}
}

int	PmergeMe::_gallopRight(deq_int& arr, const int& key, const int& b_pos, const int& a_len)
{
	int	left(0);
	int	right(1);

	if (key < arr[b_pos])
	{
		return (0);
	}
	else
	{
		while (right < a_len && arr[b_pos + right] <= key)
		{
			left = right;
			right = (right << 1) + 1;

			if (right <= 0)
			{
				right = a_len;
			}
		}
		if (right > a_len)
		{
			right = a_len;
		}
	}

	++left;

	int	mid;
	while (left < right)
	{
		mid = left + ((right - left) >> 1);

		if (key < arr[b_pos + mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return (right);
}

int	PmergeMe::_gallopLeft(deq_int& arr, const int& key, const int& pos, const int& b_len)
{
	int	left(0);
	int	right(1);

	if (key > arr[pos + b_len - 1])
	{
		return (b_len);
	}
	else
	{
		const int	start_pos = pos + b_len - 1;
		
		while (right < b_len && key <= arr[start_pos - right])
		{
			left = right;
			right = (right << 1) + 1;

			if (right <= 0)
			{
				right = b_len;
			}
		}
		if (right > b_len)
		{
			right = b_len;
		}

		int	tmp = left;
		left = b_len - 1 - right;
		right = b_len - 1 - tmp;
	}

	++left;
	int	mid;
	while (left < right)
	{
		mid = left + ((right - left) >> 1);

		if (key <= arr[pos + mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return right;
}

void	PmergeMe::_mergeLeft(deq_int& arr, const int& start1, const int& len1, const int& start2, const int& len2)
{
	deq_int	tmp(len1);
	for (int i(0); i < len1; ++i)
	{
		tmp.at(i) = arr.at(start1 + i);
	}

	int	insert_idx = start1;
	int	run_b_idx = start2;
	int	tmp_idx = 0;

	int left_run_len = len1;
	int	right_run_len = len2;

	while (left_run_len != 0 && right_run_len != 0)
	{
		if (arr[run_b_idx] < tmp[tmp_idx])
		{
			arr[insert_idx++] = arr[run_b_idx++];
			right_run_len--;
		}
		else
		{
			arr[insert_idx++] = tmp[tmp_idx++];
			left_run_len--;
		}
	}
	if (left_run_len != 0)
	{
		for (int i(0); i < left_run_len; ++i)
		{
			arr[insert_idx + i] = tmp[tmp_idx + i];
		}
	}
	else
	{
		for (int i(0); i < right_run_len; ++i)
		{
			arr[insert_idx + i] = arr[run_b_idx + i];
		}
	}
}

void	PmergeMe::_mergeRight(deq_int& arr, const int& start1, const int& len1, const int& start2, const int& len2)
{
	deq_int	tmp(len2);
	for (int i(0); i < len2; ++i)
	{
		tmp.at(i) = arr.at(start2 + i);
	}

	int	insert_idx = start2 + len2 - 1;
	int run_a_idx = start1 + len1 - 1;
	int	tmp_idx = len2 - 1;

	int	left_run_len(len1);
	int right_run_len(len2);

	while (left_run_len != 0 && right_run_len != 0)
	{
		if (arr[run_a_idx] > tmp[tmp_idx])
		{
			arr[insert_idx--] = arr[run_a_idx--];
			left_run_len--;
		}
		else
		{
			arr[insert_idx--] = tmp[tmp_idx--];
			right_run_len--;
		}
	}

	if (right_run_len != 0)
	{
		for (int i(0); i < right_run_len; ++i)
		{
			arr[start1 + i] = tmp[i];
		}
	}
}

void	PmergeMe::_merge(deq_int& arr, const int& idx)
{
	int	a_stack_pos = _run_base[idx];
	int a_stack_len = _run_len[idx];
	int	b_stack_pos = _run_base[idx + 1];
	int b_stack_len = _run_len[idx + 1];

	_run_len[idx] = a_stack_len + b_stack_len;

	if (idx == (_run_stack_size - 3))
	{
		_run_base[idx + 1] = _run_base[idx + 2];
		_run_len[idx + 1] = _run_len[idx + 2];
	}
	--_run_stack_size;

	int	left = _gallopRight(arr, arr[b_stack_pos], a_stack_pos, a_stack_len);

	if (a_stack_len == left)
	{
		return ;
	}
	a_stack_pos += left;
	a_stack_len -= left;

	int	right = _gallopLeft(arr, arr[a_stack_pos + a_stack_len - 1], b_stack_pos, b_stack_len);

	if (right == 0)
	{
		return ;
	}

	b_stack_len = right;
	if (a_stack_len <= b_stack_len)
	{
		_mergeLeft(arr, a_stack_pos, a_stack_len, b_stack_pos, b_stack_len);
	}
	else
	{
		_mergeRight(arr, a_stack_pos, a_stack_len, b_stack_pos, b_stack_len);
	}
}

void	PmergeMe::_mergeForce(deq_int& arr)
{
	while (_run_stack_size > 1)
	{
		if (_run_stack_size > 2 && _run_len[_run_stack_size - 3] < _run_len[_run_stack_size - 1])
		{
			_merge(arr, _run_stack_size - 3);
		}
		else
		{
			_merge(arr, _run_stack_size - 2);
		}
	}
}

void	PmergeMe::_merge(deq_int& arr)
{
	while (_run_stack_size > 1)
	{
		if ((_run_stack_size > 2 && (_run_len[_run_stack_size - 3] <= _run_len[_run_stack_size - 2] + _run_len[_run_stack_size - 1]))\
			|| (_run_stack_size > 3 && (_run_len[_run_stack_size - 4] <= _run_len[_run_stack_size - 3] + _run_len[_run_stack_size - 2])))
		{
			if (_run_len[_run_stack_size - 3] < _run_len[_run_stack_size - 1])
			{
				_merge(arr, _run_stack_size - 3);
			}
			else
			{
				_merge(arr, _run_stack_size - 2);
			}
		}
		else if (_run_len[_run_stack_size - 2] <= _run_len[_run_stack_size - 1])
		{
			_merge(arr, _run_stack_size - 2);
		}
		else
		{
			break ;
		}
	}
}

void	PmergeMe::_timSort(deq_int& arr)
{
	int	left(0);
	int right(arr.size());
	int	size(right);
	if (size < 2)
	{
		return ;
	}

	int	increaseRange;
	if (size < 32)
	{
		increaseRange = _getAscending(arr, left, right);
		_BinaryInsertionSort(arr, left, right, increaseRange);
		return ;
	}

	int	minRun = _calMinRunLength(size);
	std::cout << "--------------------------\n";
	std::cout << minRun << std::endl;

	do
	{
		increaseRange = _getAscending(arr, left, right);

		if (increaseRange < minRun)
		{
			const int	runLen = size < minRun ? size : minRun;

			_BinaryInsertionSort(arr, left, left + runLen, left + increaseRange);
			increaseRange = runLen;
		}
		_pushRun(left, increaseRange);
		_merge(arr);

		left += increaseRange;
		size -= increaseRange;
	}
	while (size != 0)
		;
	_mergeForce(arr);
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
	/*
	 *  Vector Sorting 
	 */
	clock_t	start = std::clock();
	_timSort(this->_sort_vec);
	// std::sort(this->_sort_vec.begin(), this->_sort_vec.end());
	clock_t	end = std::clock();

	/*
	 *  Run re-initialize 
	 */
	this->_run_base.assign(36, 0);
	this->_run_len.assign(36, 0);

	this->_vector_time = static_cast<double>(end - start) / (double)1000;

	/*
	 *  Deque Sorting 
	 */
	start = std::clock();
	_timSort(this->_sort_deque);
	end = std::clock();

	this->_deque_time = static_cast<double>(end - start) / (double)1000;
}

void	PmergeMe::printRes()
{
	std::cout << "After:	"; 
	_printContainer(this->_sort_vec);
	/*
	 *  For Debug
	 */
	std::cout << "=======================\n";
	std::cout << ((std::is_sorted(_sort_vec.begin(), _sort_vec.end()) == true) ?  "Vector Sorted" : "Vector Not sorted") << std::endl;
	std::cout << ((std::is_sorted(_sort_deque.begin(), _sort_deque.end()) == true) ? "Deque Sorted" : "Deque Not sorted") << std::endl;
	std::cout << "=======================\n";
	std::cout << "Time to process a range of " << this->_ac << " elements with std::vector : " << this->_vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_ac << " elements with std::deque  : " << this->_deque_time << " us" << std::endl;
}
