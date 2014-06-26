#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()

using namespace std;
template<class T> inline void chmax(T& a, T b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, T b) { if(b < a) a = b; }

int main() {
	bool keys[(int)'z'+1];
	rep(i,(int)'z'+1) {
		keys[i] = false;
	}
	keys['y']=true; keys['u']=true; keys['i']=true;
	keys['o']=true; keys['p']=true;
	keys['h']=true; keys['j']=true;
	keys['k']=true; keys['l']=true;
	keys['n']=true; keys['m']=true;

	string a_str;
	bool is_right_back;
	bool is_right;
	bool is_first;
	int cnt;
	while(cin >> a_str) {
		is_first = true;
		cnt = 0;
		if (a_str[0] == '#') { break; }
		rep(i,a_str.size()) {
			if (!is_first) {
				is_right = keys[(int)a_str[i]];
				if (is_right != is_right_back) {
					cnt++;
				}
			}
			is_right_back = keys[(int)a_str[i]];
			is_first = false;
		}
		cout << cnt << endl;
	}

	return 0;
}
