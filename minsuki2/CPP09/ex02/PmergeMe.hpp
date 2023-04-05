
#pragma once

#include <iomanip>
#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#define MAX 100000
#define	K	5
enum e_container { LST, VEC };

class PmergeMe {
	public:
		PmergeMe(const char* const argv[], std::string str_array[]);
		PmergeMe(const std::string strArray[]);
		PmergeMe(const PmergeMe& obj);
		~PmergeMe(void);

		PmergeMe&		operator=(const PmergeMe& obj);
		void			printSequnce(const std::string str_array[]) const;
		void			sortSequnceDeque(const std::string str_array[]);
		void			sortSequnceVector(const std::string str_array[]);
		std::size_t 	calculateNanoPeriod(timespec& begin_ts, timespec& end_ts);
		void			setPeriodDeque(timespec& begin_ts, timespec& end_ts);
		void			setPeriodVector(timespec& begin_ts, timespec& end_ts);
		void			pushDataDeque(const std::string str_array[]);
		void			pushDataVector(const std::string str_array[]);
		void			printPeriod(void);

		class InvaildInput : public std::exception {
			const char*		what(void) const throw();
		};
		class InvaildSet : public std::exception {
			const char*		what(void) const throw();
		};


	private:
		std::deque<unsigned int>			seq_deque_;
		std::vector<unsigned int>		seq_vector_;
		double							lst_period_;
		double							vec_period_;
		std::size_t						n_element;

		void			mergeInsertionSortDeque(std::size_t p1, std::size_t p3);
		void			mergeInsertionSortVector(std::size_t p1, std::size_t p3);
		void			InsertionSortDeque(std::size_t p1, std::size_t p2);
		void			InsertionSortVector(std::size_t p1, std::size_t p2);
		void			mergePartDeque(std::size_t p1, std::size_t p2, std::size_t p3);
		void			mergePartVector(std::size_t p1, std::size_t p2, std::size_t p3);
};


/*
 * postive integer sequence
 * merge-inster sort algorithm
 */
