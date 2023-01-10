#include <exception>
#include <iostream>

int main(void)
{
	std::string			key;

	while (true)
	{
		std::cin >> key;
		if (key == "cause")
			throw (std::exception());
	}
	return (0);
}
