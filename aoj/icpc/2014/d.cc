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



bool is_check_encode(string s, const string &encode_s) {
	bool is_used_alpha[256];
	REP(i,'a',('z'+1)) {
		is_used_alpha[i] = false;
	}

	is_used_alpha['a'] = true;
	rep(i,s.size()) {
		if (! is_used_alpha[s[i]]) {
			is_used_alpha[s[i]]=true;
			s[i] = (char)(s[i] - 1);
		}
	}

	return s == encode_s;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;

	while(true) {
		cin >> s;

		if (s[0] == '#') { break; }
		int N = s.size();
		vector<string> anses;
		
		rep(i,1<<N) {
			int ii = i;
			string tmp_s(s);

			bool is_ok = true;
			rep(j,N) {
				if ((ii & 1)) {  //flagついてる時
					if ((tmp_s[j]+1) <= 'z') {
						tmp_s[j] = (char)(tmp_s[j] + 1);
					}
					else {
						is_ok = false;	
						break;
					}
				}
				ii = ii >> 1;
			}

			if (is_ok && is_check_encode(tmp_s,s)) {
				anses.push_back(move(tmp_s));
			}
		}
		sort(ALL(anses));
		cout << anses.size() << endl;
		if (anses.size() <= 10) {
			rep(i,anses.size()) {
				cout << anses[i] << endl;
			}
		}
		else {
			rep(i,5) {
				cout << anses[i] << endl;
			}
			REP(i,anses.size()-5,anses.size()) {
				cout << anses[i] << endl;
			}
		}
	}

	return 0;
}
