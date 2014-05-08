#include<iostream>
#define MAX_N 100
using namespace std;
long long memo[MAX_N];

long long fibo(int n) {
	if (n <= 1) { return n;}
	if (memo[n] != 0) { return memo[n]; }
	return memo[n] = fibo(n-1) + fibo(n-2);
}

int main() {
	cout << fibo(100) << endl;
	return 0;
}