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

struct Danger {
	int D; //距離
	int P; //期待値
	bool operator<(const Danger& right) const {
		return D > right.D;
	}
};

int main() {
	int N;
	long long M;
	int D,P;
	while(cin >> N >> M) {
		if (N==0&&M==0) { break; }
		vector<Danger> dangers;
		rep(i,N) {
			cin >> D >> P;
			Danger a_danger;
			a_danger.D = D;
			a_danger.P = P;
			dangers.push_back(a_danger);
		}
		sort(ALL(dangers));
		int ans=0;
		rep(i,dangers.size()) { //P（期待値）が高い順
			if (M > 0) {
				if (dangers[i].D >= M) {
					dangers[i].D = dangers[i].D - M;
					M = 0;
				}
				else {
					M = M - dangers[i].D;
					dangers[i].D = 0;
				}
			}
			ans += dangers[i].D * dangers[i].P;
		}
		cout << ans << endl;
	}

	return 0;
}
