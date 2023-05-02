#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <deque>
#include <ctime>

typedef std::vector<std::pair<int, int> >	vec_pair;
typedef std::vector<int>					vec_int;
typedef std::deque<int>						deq_int;

class PmergeMe
{
	class	InvalidArgument : public std::exception
	{
		public :
			const char*	what() const throw();
	};

private:
	vec_int				_run_base;
	vec_int				_run_len;
	int					_run_stack_size;

	vec_int				_sort_vec;
	deq_int				_sort_deque;
	double				_vector_time;
	double				_deque_time;
	const int			_ac;
	int					_min_run;

	PmergeMe(const PmergeMe& other);
	PmergeMe&operator=(const PmergeMe& other);

	bool	_argumentCheckWithInit(const int& argc, char** argv);
	int		_checkVal(size_t nb, int pn);
	int		_ftAtoi(const char *str);
	void	_printContainer(const vec_int& vec);
	void	_printContainer(const deq_int& vec);

	/**
	 *  Vector Timsort
	 */
	int		_calMinRunLength(int size);
	void	_reverse(vec_int& arr, int left, int right);
	int		_getAscending(vec_int& arr, const int& left, const int& right);
	int		_binarySearch(const vec_int& a, const int& key, int left, int right);
	void	_BinaryInsertionSort(vec_int& arr, const int& left, const int& right, int start);
	void	_binaryInsertionSortSetter(vec_int& arr);
	int		_gallopRight(vec_int& arr, const int& key, const int& pos, const int& a_len);
	int		_gallopLeft(vec_int& arr, const int& key, const int& pos, const int& b_len);
	void	_mergeForce(vec_int& arr);
	void	_mergeLeft(vec_int& arr, const int& a_stack_pos, const int& a_stack_len, const int& b_stack_pos, const int& b_stack_len);
	void	_mergeRight(vec_int& arr, const int& a_stack_pos, const int& a_stack_len, const int& b_stack_pos, const int& b_stack_len);
	void	_merge(vec_int& arr, const int& idx);
	void	_merge(vec_int& arr);
	void	_pushRun(const int& runBase, const int& runLen);
	void	_timSort(vec_int& arr);

	/**
	 *  Deque Timsort
	 */
	void	_reverse(deq_int& arr, int left, int right);
	int		_getAscending(deq_int& arr, const int& left, const int& right);
	int		_binarySearch(const deq_int& a, const int& key, int left, int right);
	void	_BinaryInsertionSort(deq_int& arr, const int& left, const int& right, int start);
	void	_binaryInsertionSortSetter(deq_int& arr);
	int		_gallopRight(deq_int& arr, const int& key, const int& pos, const int& a_len);
	int		_gallopLeft(deq_int& arr, const int& key, const int& pos, const int& b_len);
	void	_mergeForce(deq_int& arr);
	void	_mergeLeft(deq_int& arr, const int& a_stack_pos, const int& a_stack_len, const int& b_stack_pos, const int& b_stack_len);
	void	_mergeRight(deq_int& arr, const int& a_stack_pos, const int& a_stack_len, const int& b_stack_pos, const int& b_stack_len);
	void	_merge(deq_int& arr, const int& idx);
	void	_merge(deq_int& arr);
	void	_timSort(deq_int& arr);

public:
	PmergeMe(const int& argc, char** argv);
	~PmergeMe();

	void	printRes();
	void	ftSort();
};
