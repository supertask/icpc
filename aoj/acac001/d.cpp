/* WA */
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

int main() {
	int s,t;
	int u,v;
	int V,E,Q;

	cin >> V >> E;
	vector<vector<int> > p(2*E); 

	rep(i,E) {
		cin >> s >> t;
		p[s].push_back(t); 	
		p[t].push_back(s); 	
	}

	/*
	rep(i,2*E) {
		cout << i << ": ";
		rep(j,p[i].size()) {	
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	*/

	cin >> Q;
	rep(i,Q) {
		cin >> u >> v;
		sort(all(p[u]));
		cout << binary_search(all(p[u]),v) << endl;
	}

	return 0;
}
