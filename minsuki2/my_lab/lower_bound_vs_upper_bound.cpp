#include <iostream>
#include <map>

int main(void) {
	// const std::string& a = "2011-01";
	// const std::string& b = "2011-02";
	const std::string& c = "2011-03";

	std::map<const std::string, int> m;

	// m.insert(std::make_pair(a, 5));
	// m.insert(std::make_pair(b, 6));
	m.insert(std::make_pair(c, 7));


	// a < b ? std::cout << a << " < " << b : std::cout << a << " >= " << b; std::cout << std::endl;

	std::map<const std::string, int>::iterator itlow = m.lower_bound("2011-02");
	std::map<const std::string, int>::iterator itup = m.upper_bound("2011-02");
	std::cout << "result : " << itlow->first << " " << itup->first << std::endl;

}
