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
	int N;
	int w,v;
	vector<int> ws,vs;
	int W;

	cin >> N;
	rep(i,N) {
		cin >> w >> v;
		ws.push_back(w);
		vs.push_back(v);
	}
	cin >> W;

	int dp[N+1][W+1];
	for(int i = n-1; i >= 0; i--) {
		rep(j,W+1) {
			if (j > ws[i]) {
				dp[i][j] = dp[i+1][j];
			}
			else {
				dp[i][j] = max(dp[i+1][j],);
			}
		}
	}
	cout <<  dp[0][W] << endl;
	

	return 0;
}
