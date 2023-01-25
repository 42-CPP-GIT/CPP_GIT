

#include <iostream>
#include <set>

using namespace std;

int main(void) {
	set<int>	s;

	s.insert(3);
	s.insert(6);
	s.insert(7);
	s.insert(3);

	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		std::cout << "val : " << *it << std::endl;
	}
}

