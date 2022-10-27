#include <iostream>

int	main()
{
	int a(10);
	char	tast[] = "this is test";
	char *pos = tast;
	std::string	test = std::to_string(a);
	test += 'x';
	test.at(0) = 'x';
	std::cout << test << std::endl;
	std::cout << tast << std::endl;
	std::cout << pos << std::endl;
	std::string	str = "Hello World";
	str += 'x';
	str.append(" is it possible?");
	std::cout << str << std::endl;
	std::cout << str.length() << std::endl;
	std::cout << str.size() << std::endl;
	std::cout << str.capacity() << std::endl;
	std::cout << str.max_size() << std::endl;
	str.at(0) = 'h';
	std::cout << str << std::endl;
}
