/*
 * 宇宙ヤシガニ（枝狩り問題）
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2012
 * WA
 */
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
	// x=1,000,000
	// y=1,000
	// z=100

	int min_m=INT_MAX,m=0;
	int E;
	int x,zz;
	while(cin >> E, E) {
		min_m = E;
		rep(z,100) {
			zz = E - z*z*z;
			if (zz >= 0) {
				rep(y,1000) {
					x = zz - y*y;
					if (x >= 0) {
						chmin(min_m, x + y + z);
					}
					else { break; }
				}
			}
			else { break; }
		}
		cout << min_m << endl;
		
	}

	return 0;
}
