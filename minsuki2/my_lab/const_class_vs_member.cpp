
#include <iostream>

using namespace std;


class AAA {
	public:
		AAA( int num_val ) { this->num_ = num_val; }
		void add( int n ) { this->num_ += n; }
		void showData() { cout << this->num_ << endl; }

	private:
		int	num_;
};

class BBB {
	public:
		BBB( int num_val ) { this->num_ = num_val; }
		void showData() const { cout << "[func const call] "  << this->num_ << endl; }
		void showData() { cout << "[func just call] " << this->num_ << endl; }

	private:
		int	num_;
};

class CCC {
	public:
		CCC( int num_val ) : num_(num_val) {}		// must list initialize
		void showData() const { cout << "[func const call] "  << this->num_ << endl; }
		// void showData() { cout << "[func just call] " << this->num_ << endl; }

	private:
		int	const num_;
};

int main( void ) {
	const AAA aaa(10);
	// a.add(10);			// Compile Error
	// a.showData();		// Compile Error

	const BBB const_bbb(10);
	BBB just_bbb(70);

	const_bbb.showData();			// const call
	just_bbb.showData();			// just call

	const CCC const_ccc(13);
	CCC just_ccc(75);

	const_ccc.showData();			// const call
	just_ccc.showData();			// just call -> if it dNot... const call
	return 0;
}
