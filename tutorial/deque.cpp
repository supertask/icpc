#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void lambda(int x) 
{
	cout << x << endl;
}

int main()
{
	deque<int> deq;
	
	deq.push_front(3);
	deq.push_back(1);
	for_each(deq.begin(), deq.end(), lambda);

	return 0;
}
