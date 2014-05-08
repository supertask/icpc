/* TE */
#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<climits>
#define reps(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) reps(i,0,n)
#define all(c) (c).begin(), (c).end()
using namespace std;
/*
typedef struct element {
	element () {
		//index = 0;
		value = INT_MAX;
	}
	//int index;
	int value;
	
	bool operator<(const element& right) const {
		return value < right.value;
	};
} Element;
*/

int main() {
	int n,q;
	int x,y;
	bool is_find;

	cin >> n >> q;	
	int a[100000];
	map<int,int> rev_a;
	
	rep(i,n) {
		a[i] = INT_MAX;
	}

	rep(i,q) {
		cin >> is_find >> x >> y;
		if (is_find) {
			sort(a,a+n);
			rep(j,n) {
				cout << "index = " << j << " value = " << a[j] << endl;	
			}
			rep(j,n) {
				cout << j << endl;
				if (x <= rev_a[a[j]] && rev_a[a[j]] <= y) {
					cout << a[j] << endl;
					break;		
				}
			}
		}
		else {
			a[x] = y;
			rev_a[y] = x;
		}
	}

	return 0;
}
