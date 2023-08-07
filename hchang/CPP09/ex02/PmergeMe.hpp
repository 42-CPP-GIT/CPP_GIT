#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
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
		PmergeMe(const PmergeMe& other);
		PmergeMe&operator=(const PmergeMe& other);
		std::vector<unsigned int>	_sortedVec;
		std::deque<unsigned int>	_sortedDeque;
		const int					_argc;
		double						_vectorTime;
		double						_dequeTime;

		// vector
		void						_mergeVec(std::vector<unsigned int>& vec, int left, int mid, int right);
		void						_insertVec(std::vector<unsigned int>& vec, int left, int right);
		void						_fordJohnsonVec(std::vector<unsigned int>& vec);

		// deque
		void						_mergeDeque(std::deque<unsigned int>& deq, int left, int mid, int right);
		void						_insertDeque(std::deque<unsigned int>& deq, int left, int right);
		void						_fordJohnsonDeque(std::deque<unsigned int>& deq);

		// util
		bool						_checkArgument(const int& argc, char** argv);
		unsigned int				_arryToInt(const char *str);
		void						_printContainer(const std::vector<unsigned int>& vec);
		void						_printContainer(const std::deque<unsigned int>& deq);
		
	public:
		PmergeMe(const int& argc, char** argv);
		~PmergeMe();
		void						printRes();
		void						sort();
};
