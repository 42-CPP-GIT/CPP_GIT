#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
	class	InvalidArgument : public std::exception
	{
		public :
			const char*	what() const throw();
	};

private:
	std::vector<int>	_sort_vec;
	std::deque<int>		_sort_deque;
	double				_vector_time;
	double				_deque_time;

	PmergeMe(const PmergeMe& other);
	PmergeMe&operator=(const PmergeMe& other);

	bool	ArgumentCheckWithInit(const int& argc, char** argv);
	int		check_val(size_t nb, int pn);
	int		ft_atoi(const char *str);

// 	template<typename Iterator>
// 	void merge(Iterator begin, Iterator mid, Iterator end)
// 	{
// 		std::vector<typename Iterator::value_type> temp;

// 		Iterator left = begin;
// 		Iterator right = mid;

// 		while (left != mid && right != end)
// 		{
// 			if (*left <= *right)
// 			{
// 				temp.push_back(*left);
// 				++left;
// 			}
// 			else
// 			{
// 				temp.push_back(*right);
// 				++right;
// 			}
// 		}

// 		while (left != mid)
// 		{
// 			temp.push_back(*left);
// 			++left;
// 		}

// 		while (right != end)
// 		{
// 			temp.push_back(*right);
// 			++right;
// 		}

// 		std::copy(temp.begin(), temp.end(), begin);
// 	}

// 	template<typename T>
// 	void insertionSort(T& container)
// 	{
// 		typename T::iterator it = container.begin();
// 		typename T::iterator end = container.end();

// 		for (typename T::iterator i = it + 1; i != end; ++i)
// 		{
// 			typename T::value_type key = *i;
// 			typename T::iterator j = i - 1;
// 			while (j >= it && *j > key) {
// 				*(j + 1) = *j;
// 				--j;
// 			}
// 			*(j + 1) = key;
// 		}
// 	}

// 	template<typename T>
// 	void mergeInsertionSort(T& container, int left, int right, int midrun)
// {
//     if (right - left + 1 <= midrun)
//     {
//         T newContainer(container.begin() + left, container.begin() + right + 1);
//         insertionSort(newContainer);
//         std::copy(newContainer.begin(), newContainer.end(), container.begin() + left);
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     mergeInsertionSort(container, left, mid, midrun);
//     mergeInsertionSort(container, mid + 1, right, midrun);
//     merge(container.begin() + left, container.begin() + mid + 1, container.begin() + right + 1);
// 	}

// 	template<typename T>
// 	void print_container(const T& container)
// 	{
// 		typename T::const_iterator it;

// 		for (it = container.begin(); it != container.end(); ++it)
// 		{
// 			std::cout << *it << " ";
// 		}
// 		std::cout << std::endl;
// 	}

/*******/

	template<typename Iterator>
	void merge(Iterator begin, Iterator mid, Iterator end)
	{
		std::vector<typename Iterator::value_type> temp;

		Iterator left = begin;
		Iterator right = mid;

		while (left != mid && right != end)
		{
			if (*left <= *right)
			{
				temp.push_back(*left);
				++left;
			}
			else
			{
				temp.push_back(*right);
				++right;
			}
		}

		while (left != mid)
		{
			temp.push_back(*left);
			++left;
		}

		while (right != end)
		{
			temp.push_back(*right);
			++right;
		}

		std::copy(temp.begin(), temp.end(), begin);
	}

	//template<typename Iterator>
	//void insertionSort(Iterator begin, Iterator end)
	//{
	//	for (Iterator i = begin + 1; i != end; ++i)
	//	{
	//		typename Iterator::value_type key = *i;
	//		Iterator j = i - 1;
	//		while (j >= begin && *j > key) {
	//			*(j + 1) = *j;
	//			j -= 1;
	//		}
	//		*(j + 1) = key;
	//	}
	//}
	template<typename Iterator>
	void insertionSort(Iterator begin, Iterator end)
	{
		for (Iterator i = begin + 1; i != end; ++i)
		{
			typename Iterator::value_type key = *i;
			Iterator j = i;
			while (j != begin && *(j - 1) > key) {
				*j = *(j - 1);
				--j;
			}
			*j = key;
		}
	}
	template<typename Iterator>
	void mergeInsertionSort(Iterator begin, Iterator end, int midrun)
	{
		if (std::distance(begin, end) <= midrun)
		{
			insertionSort(begin, end);
			return;
		}
		Iterator mid = begin + std::distance(begin, end) / 2;
		mergeInsertionSort(begin, mid, midrun);
		mergeInsertionSort(mid, end, midrun);
		merge(begin, mid, end);
	}

	template<typename Container>
	void print_container(const Container& container)
	{
		typename Container::const_iterator it;

		for (it = container.begin(); it != container.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

public:
	PmergeMe(const int& argc, char** argv);
	~PmergeMe();

	void	print_res();
	void	ft_sort();
};
