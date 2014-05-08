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

int main() {
	int n;
	int x,y;
	int xs[100],ys[100];
	vector<double> lines;
	
	cin >> n;
	rep(i,n) {
		cin >> x >> y;
		xs[i] = x;
		ys[i] = y;
	}
	/* 
	 * O(n^2 - n) = O(n^2)
	 * 抑えたとして，半分 O(1/2 * (n^2-n))
	 */ 
	rep(i,n) {
		rep(j,n) {
			if (i != j) {
				lines.push_back(sqrt(pow(xs[i]-xs[j],2) + pow(ys[i]-ys[j],2)));
			}
		}
	}
	cout << setprecision(6) << fixed;
	cout << *max_element(all(lines)) << endl;

	return 0;
}

