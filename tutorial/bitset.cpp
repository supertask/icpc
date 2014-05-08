#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	bitset<8> bit_integer(0);
	bitset<8> bit_string("100110");

	if (!bit_integer[0]) {
		cout << "1st" << endl;
	}
	
	cout << "2nd " << bit_integer << endl;
	if (bit_integer.none()) {
		cout << "すべて0" << endl;
	}


	bit_integer.set(7);
	cout << "2nd " << bit_integer << endl;
	
	if (bit_integer.any()) {
		cout << "1が存在" << endl;
	}

	return 0;
}
