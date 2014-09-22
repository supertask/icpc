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

struct Kuku {
	int w;
	int h;
	bool operator<(const Kuku &right) const {
		return  w < right.w;
	}
};


int main() {
	int N;
	int sums = 0;
	vector<vector<Kuku> > kukus(82); //0~81

	cin >> N;
	REP(h,1,10) { //1~9
		REP(w,1,10) { //1~9
			int num = w*h;
			Kuku kuku;
			kuku.w = w;
			kuku.h = h;
			kukus[num].push_back(kuku);
			sums += num;
		}
	}
	int diff = sums - N;
	sort(ALL(kukus[diff]));
	rep(i,kukus[diff].size()) {
		cout << kukus[diff][i].w << " x " << kukus[diff][i].h << endl;
	}

	return 0;
}
