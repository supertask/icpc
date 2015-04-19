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
	int N,K;
	int start,end;
	int p;

	cin >> N;
	vector<int> ps;
	vector<bool> is_passes(N+1,false);
	cin >> start >> end;
	cin >> K;
	rep(i,K) {
		cin >> p;
		ps.push_back(p);
	}
	bool is_yes = true;
	is_passes[start]=true; //すでに通っている.
	is_passes[end]=true; //すでに通っている.
	rep(i,ps.size()) {
		if (is_passes[ps[i]]) {
			is_yes = false;
			break;
		}
		else {
			is_passes[ps[i]] = true;
		}
	}
	if (is_yes) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }


	return 0;
}
