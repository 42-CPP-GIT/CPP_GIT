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
	 * Timsort
	 */
	int		_calMinRunLength(int size, const int min);
	void	_InsertionSortWithIter(const vec_int::iterator& begin, const vec_int::iterator& end);
	void	_timMergeWithIter(const vec_int::iterator& begin, const vec_int::iterator& mid, const vec_int::iterator& end);
	void	_timSortwithIter(const vec_int::iterator& begin, const vec_int::iterator& end);

	void	_timInsertionSortWithRef(vec_int& arr, const int& left, const int& right);
	void	_timMergeWithRef(vec_int& arr, const int& left, const int& mid, const int& right);
	void	_timSortWithRef(vec_int& arr);

	/**
	 * Ford Johnson algorithm
	 */
	void	_fordMergeWithIter(const vec_int::iterator& begin, const vec_int::iterator& mid, const vec_int::iterator& end);
	void	_fordInsertionSortWithIter(const vec_int::iterator& left, const vec_int::iterator& right);
	void	_fordJohnsonSortWithIter(const vec_int::iterator& begin, const vec_int::iterator& end);

	void	_fordMergeWithRef(std::vector<int>& arr, int left, int mid, int right);
	void	_fordInsertionSortWithRef(std::vector<int>& arr, int left, int right);
	void	_fordJohnsonSortWithRef(std::vector<int>& arr);

public:
	PmergeMe(const int& argc, char** argv);
	~PmergeMe();

	void	printRes();
	void	ftSort();
};
