#include <iostream>
#include <vector>
#include <algorithm>
#define each(numbers,func) for_each(numbers.begin(),numbers.end(),func)

using namespace std;

void lambda(int number) {
	cout << number << endl;
}

int main() {
	vector<int> numbers;
	for (int i=0; i<5; i++) {
		numbers.push_back(i);
	}

	each(numbers,lambda);
	
	return 0;
}
