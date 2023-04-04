
		// pm.printSequnce(NULL);
		// std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();
		// clock_t	t = std::clock();
		clock_gettime(CLOCK_MONOTONIC, &begin_ts);
		pm.sortSequnceList(str_array);
		// t = std::clock() - t;
		clock_gettime(CLOCK_MONOTONIC, &end_ts);
		// std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();

		// std::size_t begin_nano = 1e+9 * begin_ts.tv_sec + begin_ts.tv_nsec;
		// std::size_t end_nano = 1e+9 * end_ts.tv_sec + end_ts.tv_nsec;
		std::size_t nano_period = 1e+9 * (end_ts.tv_sec - begin_ts.tv_sec)
									+ (end_ts.tv_nsec - begin_ts.tv_nsec);

		double micro_period = static_cast<double>(nano_period) / 1e+6; // µs
		// std::cout << end_nano << " - " << begin_nano << " = " << nano_period << std::endl;
		// std::cout << nano_period / 1e+6 << '.' << nano_period % static_cast<std::size_t>(1e+6) << std::endl;
		std::cout << std::fixed << std::setprecision(5) << micro_period << std::endl;
		// std::cout << t / (double)1000 << std::endl;
		// std::chrono::nanoseconds nano = EndTime - StartTime;
		// std::cout << "for문 실행 시간(nanoseconds) : " << nano.count() / 1000 << std::endl;

