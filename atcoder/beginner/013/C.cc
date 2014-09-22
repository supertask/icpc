/* WA 100点 */
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
	int N,H;
	int A,B,C,D,E;
	int mini = INT_MAX;

	cin >> N >> H;
	cin >> A >> B >> C >> D >> E;
	rep(Y,N+1) {
		rep(X,N+1-Y) {
			if ((H + B*X + D*Y -(N - X - Y)*E) > 0)
			{
				int ans = A*X+C*Y;
				chmin(mini,ans);
			}
		}
	}
	cout << mini << endl;

	return 0;
}
