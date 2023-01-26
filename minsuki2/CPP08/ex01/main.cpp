#include "Span.hpp"

int main() {

	std::cout << BOLDCYAN << "[CASE 1] : Given main Test --- "
	  		  << RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << BOLDCYAN << "[CASE 2] : my Test --- "
	  		  << RESET << std::endl;
	{
		Span sp = Span(7);

		sp.addNumber(6);
		sp.addNumber(1);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(19);
		sp.addNumber(23);
		std::cout << "ShortestSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan  : " << sp.longestSpan() << std::endl;
		std::cout << "Current Span : "; sp.showSpanNumber();

		std::cout << std::endl
				  << BOLDBLUE << " --- 중복 테스트 --- " << RESET << std::endl;
		try {
			sp.addNumber(6);
		} catch (std::exception& e){
			std::cout << std::endl << "[Error] " << e.what() << std::endl;
		}

		sp.addNumber(11);
		std::cout << std::endl << "Current Span : "; sp.showSpanNumber();

		std::cout << std::endl
				  << BOLDYELLOW << " --- 꽉찬 테스트 --- " << RESET << std::endl;
		try {
			sp.addNumber(6);
		} catch (std::exception& e){
			std::cout << std::endl << "[Error] " << e.what() << std::endl;
		}

	}
	std::cout << std::endl
			  << BOLDCYAN << "[CASE 3] : subject more Test --- "
			  << RESET << std::endl;

	try {
		const int max = 1;
		Span sp = Span(max);
		std::srand(time(NULL));

		for (int i(0); i < max; ++i) {
			unsigned int	lotto;
			do {
				lotto = std::rand() % max;
				if (std::find(sp.getPocket().begin(), sp.getPocket().end(), lotto)
						!= sp.getPocket().end()) { lotto = max; }
			} while (lotto == max);
			sp.addNumber(lotto);
		}
		// sp.showSpanNumber();
		std::cout << "ShortestSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan : " << sp.longestSpan() << std::endl;
	} catch (std::exception& e){
		std::cout << std::endl << "[Error] " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << BOLDCYAN << "[CASE 4] : addNumber upgrade Test --- "
			  << RESET << std::endl;
	try {
		Span sp = Span(9);		// 9 -> 10 -> 11
		std::vector<int> input;
		std::srand(time(NULL));

		input.push_back(24);
		input.push_back(79);
		input.push_back(50);
		input.push_back(83);
		input.push_back(9);
		sp.addNumber(input.begin(), input.end());
		// sp.addNumber(input.begin(), input.end()); // 중복 테스트
		std::cout << "Current Span : "; sp.showSpanNumber();
		std::cout << "ShortestSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan  : " << sp.longestSpan() << std::endl;

		for (std::vector<int>::iterator it(input.begin())
				; it != input.end(); ++it) {
			unsigned int	lotto;
			while (true) {
				lotto = 1 + std::rand() % 100;
				if (std::find(sp.getPocket().begin(), sp.getPocket().end(), lotto) == sp.getPocket().end()
					&& std::find(input.begin(), input.end(), lotto) == input.end()) {
					break ;
				}
			}
			*it = lotto;
		}
		sp.addNumber(input.begin(), input.end());
		std::cout << "Current Span : "; sp.showSpanNumber();
		std::cout << "ShortestSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan  : " << sp.longestSpan() << std::endl;


		sp.addNumber(100);
		std::cout << "Current Span : "; sp.showSpanNumber();
		std::cout << "ShortestSpan : " <<  sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan  : " << sp.longestSpan() << std::endl;

	} catch (std::exception& e){
		std::cout << std::endl << "[Error] " << e.what() << std::endl;
	}
	return 0;
}
