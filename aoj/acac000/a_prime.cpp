/* AC */
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
using namespace std;

vector<int> get_divisors(int n) {
	vector<int> res;
	for (int i = 1; i*i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i*i != n) { res.push_back(n/i); }
		}
	}
	return res;
}

int main() {
	int n;
	vector<int> divisors;
	vector<int> primes;

	cin >> n;
	divisors = get_divisors(n);
	sort(all(divisors));
	cout << n << ":";
	rep(i,divisors.size()) {	
		if (i != 0) { 
			while (n % divisors[i] == 0) {
				n = n / divisors[i];
				cout << " " << divisors[i] ; 
			}
		}
	}
	cout << endl;

	return 0;
}
