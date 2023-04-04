
#include "PmergeMe.hpp"
// #include <chrono> // C++11

// static void		char2ArrayToStringArray(char* argv[], std::string strArray[]) {
	// std::size_t	i = 0;
	// while (argv[i + 1]) {
		// ++i;
	// }
// }

int	main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	std::string str_array[argc];
	// char2ArrayToStringArray(argv, strArray);
	try {
		struct timespec  begin_ts, end_ts;
		PmergeMe pm(argv, str_array);

		/* Before 출력 */
		pm.printSequnce(str_array);

		/* list Sort */
		clock_gettime(CLOCK_MONOTONIC, &begin_ts);
		pm.sortSequnceList(str_array);
		clock_gettime(CLOCK_MONOTONIC, &end_ts);
		pm.setPeriod(begin_ts, end_ts, "lst");

		/* After 출력 */
		pm.printSequnce(NULL);

		/* vector Sort */
		clock_gettime(CLOCK_MONOTONIC, &begin_ts);
		pm.sortSequnceList(str_array);
		clock_gettime(CLOCK_MONOTONIC, &end_ts);
		pm.setPeriod(begin_ts, end_ts, "lst");

		/* After 출력 */
		pm.printSequnce(NULL);

		/* vector Sort */
		clock_gettime(CLOCK_MONOTONIC, &begin_ts);
		pm.sortSequnceVector(str_array);
		clock_gettime(CLOCK_MONOTONIC, &end_ts);
		pm.setPeriod(begin_ts, end_ts, "vec");

		pm.printPeriod();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
