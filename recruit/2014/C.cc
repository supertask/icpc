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


bool uru(int i) {
	if (i % 100 == 0) {
		if (i % 400 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if(i % 4 == 0) {
			return true;
		}
		else return false;
	}
}


int main() {
	int a,b;
	int cnt=0;

	cin >> a >> b;

	int tmp = 0;	
	int a_cnt=0;
	while(true) {
		if (a % 400 == 0 && (a > 400)){
			a = a / 400;
			a_cnt++;
		}
		else {
			break;
		}
	}
	int b_cnt=0;
	while(true) {
		if (b % 400 == 0 && (b > 400)){
			b = b / 400;
			b_cnt++;
		}
		else {
			break;
		}
	}
	cout << a_cnt << " " << b_cnt << endl;
	cout << a << " " << b << endl;
	REP(i,a,b+1) {
		if (uru(i)) {
			cnt++;
		}
	}
	int t = 1;
	int ans = 0;

	rep(i,b_cnt) {
		t*=400;
	}
	REP(i,1,t+1) {
		if (uru(i)) {
			ans++;
		}
	}
	dump(ans);
	dump(cnt);
	dump(t);
	cout << ans + cnt*t << endl;

	return 0;
}
