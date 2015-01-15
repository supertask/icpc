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
	int N,L;
	int l,r,c;
	vector<int> ls,rs,cs;

	cin >> N >> L;
	rep(i,N) {
		int tmpmin = 99999999;
		cin >> l >> r >> c;
		ls.push_back(l);
		rs.push_back(r);
		cs.push_back(c);
	}

	rep(i,N) {
		rep(j,L+1)
		{
			if (j < ls[i] || k > rs[j]) {
				dp[i][j] = dp[i-1][j];
			}
		}
		rep(k,ls[i],r[i]+1)
		{
			dp[i][k] = min(dp[i][k], tmpmin + cs[i]);		
			tmpmin = min(tmpmin,dp[i][k]);
		}
	}

	return 0;
}
