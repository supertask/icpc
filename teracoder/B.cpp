#include<iostream>
#include <cstdlib>
using namespace std;

int main() {
	string num;
	while (cin >> num) {
		if (num == "-1") {
			break;
		}
		int aa = 0;
		for (int i=0; i < num.length(); i++) {
			aa += (num[i] - '0');
		}
		if (aa % 10 == 0) {
			cout << "OK" << endl;
		}
		else {
			cout << "NG" << endl;
		}
	}
	return 0;
}