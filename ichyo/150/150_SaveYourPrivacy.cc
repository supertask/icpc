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
	int N,M,p;
	int K,l;

	while(cin >> N, N) {
		vector<vector<int> > infos;
		vector<int> out_infos;

		rep(n,N) {
			cin >> M;
			vector<int> info;
			rep(m,M) {
				cin >> p;
				info.push_back(p); //0オリジン			
			}
			infos.push_back(info);
		}
		cin >> K;
		rep(k,K) {
			cin >> l;
			out_infos.push_back(l);
		}
		
		vector<int> bad_mans;
		rep(i,N) {
			bool is_all_find = true;
			rep(k,K) {
				if (! binary_search(ALL(infos[i]),out_infos[k])) { //見つからない!
					is_all_find = false;
				}
			}
			if (is_all_find) {
				bad_mans.push_back(i+1);
			}
		}
		if (bad_mans.size() == 1) {
			cout << bad_mans.front() << endl;
		}
		else { //犯人が0人，または2人以上で特定できないとき
			cout << -1 << endl;
		}

		infos.clear();
		out_infos.clear();
	}

	return 0;
}
