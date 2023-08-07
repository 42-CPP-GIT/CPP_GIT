#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
		{
			std::cerr << "Error: could not open file." << std::endl;
			return (1);
		}
		else if (argc == 2)
		{
			BitcoinExchange	btc(argv[1]);
			btc.printInputFile();
		}
		else
		{
			BitcoinExchange	btc(argv[1], argv[2]);
			btc.printInputFile();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}