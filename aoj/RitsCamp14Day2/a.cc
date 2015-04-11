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
	string A,B;
	cin >> A >> B;
	bool is_match=false;

	rep(i,A.size()) {
		is_match = true;
		rep(j,B.size()) {
			if (i+j > A.size()) { 
				is_match = false;
				break;
			}
			if (! (A[i+j] == B[j] || B[j] == '_') ) {
				is_match = false;
				break;
			}
		}
		if (is_match) { break; }
	}
	cout << ((is_match) ? "Yes" : "No") << endl;

	return EXIT_SUCCESS;
}
