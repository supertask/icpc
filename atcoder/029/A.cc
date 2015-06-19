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
	int N,t;
	vector<int> niku_t[2];

	cin >> N;

	bool is_left=true;
	vector<int> ins;
	int in;
	rep(i,N) {
		cin >> in;
		ins.push_back(in);
	}

	niku_t[0].push_back(ins[0]);
	int w = 1; //0=left
	for(int i = 1; i < N; i+=2)
	{
		niku_t[w].push_back(ins[i]);
		if (i+1 < N) { niku_t[w].push_back(ins[i+1]); }
		if (w==0) { w=1; }
		else { w=0; }
	}
	
	int sum_left=0;
	rep(i,niku_t[0].size()) {
		sum_left+=niku_t[0][i];
	}

	int sum_right=0;
	rep(i,niku_t[1].size()) {
		sum_right+=niku_t[1][i];
	}
	cout << max(sum_left,sum_right) << endl;



	return 0;
}