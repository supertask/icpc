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
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //t=min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //t=max
using namespace std;

#define EPS 1.0e-10


int plus_2(int a,int b) {
	return sqrt(a*a+b*b);
}

int main() {
	int tx_1,ty_1,tx_2,ty_2,T,V;
	int N;
	int x,y;

	cin >> tx_1 >> ty_1 >> tx_2 >> ty_2 >> T >> V;
	cin >> N;
	
	
	bool is_yes = false;
	rep(i,N) {
		cin >> x >> y;
		double girl_d = plus_2(x-tx_1,y-ty_1) + plus_2(x-tx_2,y-ty_2);
		int d = T*V;
		if (girl_d <= d+EPS) is_yes=true;
	}
	cout << (is_yes ? "YES": "NO") << endl;

	return 0;
}
