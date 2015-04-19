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

const int MAX_N = 100;
const int INF = 1e+6;

int main() {
	long long d[MAX_N][MAX_N];
	int a,b;
	int N,M;
	rep(i,MAX_N) rep(j,MAX_N) d[j][i] = INF;

	cin >> N;
	cin >> a >> b;

	cin >> M;
	rep(i,M) {
		int x,y;
		cin >> x >> y;
		d[y][x] = 1; //distance=1
		d[x][y] = 1; //distance=1
	}

	REP(i,1,N+1) REP(j,1,N+1) REP(k,1,N+1) d[i][j]=min(d[i][j],d[i][k] + d[k][j]);

	REP(y,1,N+1) {
		REP(x,1,N+1) {
			cout << d[y][x] << " ";
		}
		cout << endl;
	}
	cout << d[a][b] << endl;

	return 0;
}
