#include<bits/stdc++.h>
#define dump(a) cout << (#a) << " " << a << endl
using namespace std;

vector<int> ones;
vector<int> twos;

int dfs(const int D, int point)
{
	if (D <= 0) { return 0; }

	dump(D);
	dump(point);
	for(int i=0; i<ones.size(); i++) {
		point = max(point, dfs(D-1, point+ones[i]));
	}
	dump(point);

	for(int i=0; i<twos.size(); i++) {
		point = max(point, dfs(D-2, point+twos[i]));
	}
	return point;
}

int main() {
	int D,x,y,p;
	string a;
	cin >> D;
	cin >> x;
	for(int i=0; i<x; i++) {
		cin >> a >> p;
		if (a == "D") { ones.push_back(p); }
	}
	for(int i=0; i<y; i++) {
		cin >> a >> p;
		if (a == "DD") { twos.push_back(p); }
	}
	cout << dfs(D,0) << endl;

	return EXIT_SUCCESS;
}
