
#pragma once

#include <iomanip>
#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#define MAX 100000
enum e_container { LST, VEC };

class PmergeMe {
	public:
		PmergeMe(const char* const argv[], std::string str_array[]);
		PmergeMe(const std::string strArray[]);
		PmergeMe(const PmergeMe& obj);
		~PmergeMe(void);

		PmergeMe&		operator=(const PmergeMe& obj);
		void			printSequnce(const std::string str_array[]) const;
		void			sortSequnceList(const std::string str_array[]);
		void			sortSequnceVector(const std::string str_array[]);
		std::size_t 	calculateNanoPeriod(timespec& begin_ts, timespec& end_ts);
		void			setPeriodList(timespec& begin_ts, timespec& end_ts, const std::string& which);
		void			setPeriodVector(timespec& begin_ts, timespec& end_ts, const std::string& which);
		void			pushDataList(const std::string str_array[]);
		void			pushDataVector(const std::string str_array[]);
		void			printPeriod(void);

		class InvaildInput : public std::exception {
			const char*		what(void) const throw();
		};
		class InvaildSet : public std::exception {
			const char*		what(void) const throw();
		};


	private:
		std::list<unsigned int>			seq_lst_;
		std::vector<unsigned int>		seq_vec_;
		double							lst_period_;
		double							vec_period_;
		std::size_t						n_element;
};


/*
 * postive integer sequence
 * merge-inster sort algorithm
 */
