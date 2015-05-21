#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#include<sstream>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

struct Node {
	string M;
	int depth;
	vector<Node> nodes;
}

void addNode() {
	
}

int main() {
	int N,k;
	string M;
	cin >> N;
	rep(i,N) {
		cin >> k >> M;
		add_node();
	}

	return EXIT_SUCCESS;
}
