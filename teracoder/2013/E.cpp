#include<iostream>
using namespace std;

int main() {
	int t;
	while (cin >> t) {
		if (t == 0) { break; }
		int maxx[7];
		int a;
		for (int i=0; i<t; i++) {
			cin >> a;
			if (a > 6) {
				cout << "No";
				break;
			}
			maxx[0] = a;
		}
		
	}
	
	return 0;
}