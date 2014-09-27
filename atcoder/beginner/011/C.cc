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

int cnt=0; //100回
int useNums[3] = {3,2,1};
int NG[3];


bool search(int n)
{
	if (cnt > 100) return false;
	if (n == 0) return true;

	rep(u,3) {
		int nn = n - useNums[u];
		if (nn == NG[0] || nn == NG[1] || nn == NG[2] || nn < 0)
		{
			//next
		}
		else {
			cnt++;
			bool is_yes = search(nn);
			if (is_yes) return true;
		}
	}
	return false;
}

int main()
{
	int N;

	cin >> N;
	rep(i,3) {
		cin >> NG[i];
	}
	
	if (N == NG[0] || N == NG[1] || N == NG[2]) {
		cout << "NO" << endl;
	}
	else {
		cout << (search(N) ? "YES" : "NO") << endl;
	}

	return 0;
}
