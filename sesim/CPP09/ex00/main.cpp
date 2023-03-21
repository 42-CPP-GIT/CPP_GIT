#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac < 2)
		{
			std::cerr << "Error: could not open file." << std::endl;
			return (1);
		}
		else if (ac == 2)
		{
			BitcoinExchange	btc(av[1]);
			btc.printInputFile();
		}
		else
		{
			BitcoinExchange	btc(av[1], av[2]);
			btc.printInputFile();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}