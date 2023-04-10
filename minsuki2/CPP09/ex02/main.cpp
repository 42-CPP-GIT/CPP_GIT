
#include "PmergeMe.hpp"

/*
 * < Feed Back >
 * 1. Outer 가서는 Templete 키워드 활용해서 hpp으로 작성해보기
 *
 */

int	main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	std::string str_array[argc];
	try {
		struct timespec  begin_ts, end_ts;
		PmergeMe pm(argv, str_array);

		/* Before 출력 */
		pm.printSequnce(str_array);

		/* list Sort */
		clock_gettime(CLOCK_MONOTONIC, &begin_ts);
		pm.sortSequnceDeque(str_array);
		clock_gettime(CLOCK_MONOTONIC, &end_ts);
		pm.setPeriodDeque(begin_ts, end_ts);

		/* After 출력 */

		/* vector Sort */
		clock_gettime(CLOCK_MONOTONIC, &begin_ts);
		pm.sortSequnceVector(str_array);
		clock_gettime(CLOCK_MONOTONIC, &end_ts);
		pm.setPeriodVector(begin_ts, end_ts);

		pm.printSequnce(NULL);
		pm.printPeriod();

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
