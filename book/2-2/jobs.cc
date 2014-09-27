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

const int MAX_N = 100000;

int main() {
	int N;

	cin >> N;
	pair<int, int> times[MAX_N];

	rep(i,N) {
		cin >> times[i].second;
	}
	rep(i,N) {
		cin >> times[i].first;
	}
	sort(times,times+N);

	int back_t=0;
	int cnt=0;
	rep(i,N) {
		if (back_t < times[i].second) { //second=仕事の開始時間
			cout << i+1 << endl;
			cnt++;
			back_t = times[i].first; //first=仕事の終了時間
		}
	}
	cout << "cnt = " << cnt << endl;

	return 0;
}
