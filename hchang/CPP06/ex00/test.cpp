#include <iostream>

int	main()
{

	// inf
	const char*	a = " 2147483648";
	char		*end;
	double f = strtod(a, &end);


	// inff도 valid
	// inf이면 뒤에 f인지 확인하기
	// inff이면 뒤에 다른 것이 오는 지 확인하기 (뭐가 오면 바로 터트리면 된다.)
	// _data.find("inf") npos -> 0번오면 len (3, 4)
	// 마지막 인덱스를 -> f인지
	// inf -> std::string(end) -> .len() == 0 || (.len() == 1 && (0) == "f")
	// if ((*end) && (*end) != 'f' && *(end++))
	// 	std::cout << "space\n";
	// if (*end == 'f' && *(end++))
	// 	std::cout << "err\n";
	std::cout << end << std::endl;
	std::string hey(end);
	std::cout << hey << " --> len " << hey.length() << std::endl;

	std::cout << "===========" << std::endl;
	std::cout << f << std::endl;




}
// 