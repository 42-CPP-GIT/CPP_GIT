
#include <iostream>
#include <deque>
#include <queue>

using namespace std;


int main(void) {
	// std::deque<int> d;
	// std::cout << d.back() << std::endl;
	//
	int i = 1;

	for(int i)
	{
	}

	return 0;
}






	{
		priority_queue<int> pq;
		pq.push(10);
		pq.push(20);
		pq.push(100);
		pq.push(3);

		// 우선순위 큐의 모든 요소를 인출
		while(!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
