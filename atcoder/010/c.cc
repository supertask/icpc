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
	int N,M,Y,Z,p;
	char c;
	string bs;
	map<char> stone_points;

	cin >> N >> M >> Y >> Z;
	cin >> bs;
	rep(m,M) {
		cin >> c >> p;
		stone_points[c] = p;
	}

	vector<int> dp_buf(bs.size(),0);
	rep(i,bs.size()) {
		if (i == 0) { continue; }
		dp_buf[i] += stone_points[bs[i]]; //色のボーナス
		if (bs[i-1] == bs[i]) {
			bp_buf[i] = dp_buf[i-1] + Y; //コンボボーナス
		}
	}

	return 0;
}
