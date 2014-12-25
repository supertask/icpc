#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define reps(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) reps(i,0,n)
#define all(c) (c).begin(), (c).end()
using namespace std;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return n != 1; 
}

vector<int> get_divisor(int n) {
	vector<int> res;
	for(int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) { res.push_back(n/i); }
		}
	} 
	return res;
}

vector<int> get_prime_factor(int n) {
	vector<int> res;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	}
	if (n != 1) { res.push_back(n); }
	return res;
}

int main() {	
	int n;
	vector<int> res;

	cin >> n;
	if (is_prime(n)) {
		cout << "素数" << endl;	
	}
	else {
		cout << "素数でない" << endl;	
	}
	/*
	res = get_divisor(n);
	//res = get_prime_factor(n);
	sort(all(res));
	rep(i,res.size()) {
		cout << res[i] << " ";
	}	
	cout << endl;
	*/
		
	return 0;
}

