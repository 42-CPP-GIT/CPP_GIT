#include "Span.hpp"

int main() {

	std::cout << BOLDCYAN << "[CASE 1] : Given main Test --- "
		<< RESET << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(1);
		sp.addNumber(17);
		sp.addNumber(9);
		std::cout << "ShortestSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan  : " << sp.longestSpan() << std::endl;
		std::cout << "Current Span : "; sp.showSpanNumber();

		std::cout << std::endl
				  << BOLDBLUE << " --- 중복 테스트 --- "
				  << RESET << std::endl;
		try {
			sp.addNumber(6);
		} catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}

		sp.addNumber(11);
		std::cout << std::endl << "Current Span : "; sp.showSpanNumber();

		std::cout << std::endl
				  << BOLDYELLOW << " --- 꽉찬 테스트 --- "
				  << RESET << std::endl;
		try {
			sp.addNumber(6);
		} catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}

	}

	std::cout << std::endl
			  << BOLDCYAN << "[CASE 2] : subject Test --- "
			  << RESET << std::endl;
	// Test your Span at least with a minimum of 10,000 numbers

	{
		const int max = 10000;
		Span sp = Span(max);
		std::srand(time(NULL));

		for (int i(0); i < max; ++i) {
			unsigned int	lotto;
			do {
				lotto = std::rand() % max;
				for (std::vector<unsigned int>::const_iterator	it(sp.getPocket().begin())
						; it != sp.getPocket().end()
						; ++it) {
					if (*it == lotto) { lotto = max; break ; }
				}
			} while (lotto == max);
			sp.addNumber(lotto);
		}
		// sp.showSpanNumber();
		std::cout << "ShortestSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan : " << sp.longestSpan() << std::endl;
	}
	return 0;
}
