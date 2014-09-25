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

int main() {
	int a,b;
	int up_cnt=0;
	int down_cnt=0;
	int i;

	cin >> a >> b;
	i = a;
	while(true) {
		if (i == b) { break; }
		if (i > 9) { i = 0; }
		i++;
		up_cnt++;
	}
	i = a;
	while(true) {
		if (i == b) { break; }
		if (i < 0) { i = 9; }
		i--;
		down_cnt++;
	}

	if (up_cnt > down_cnt) {
		cout << down_cnt << endl;
	}
	else {
		cout << up_cnt << endl;
	}

	return 0;
}
