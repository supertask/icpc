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

char mapp[100][100];

int main() {
	int T;
	int X,Y,N,w,k;
	cin >> T;
	rep(t,T) {
		rep(x,100) {
			rep(y, 100) {
				mapp[x][y] = '.';
			}
		}
		cin >> X >> Y;
		cin >> N;
		rep(n,2*N) {
			cin >> w >> k;
			if (k == 0) {
				rep(i,100) {
					if (n % 2 == 0) {
						mapp[i][w-1] = 'W';
					}
					else {
						mapp[i][w-1] = 'B';
					}
				}
			}
			else if (k == 1) {
				rep(i,100) {
					if (n % 2 == 0) {
						mapp[w-1][i] = 'W';
					}
					else {
						mapp[w-1][i] = 'B';
					}
				}
			}
		}
		rep(y,Y) {
			rep(x,X) {
				cout << mapp[x][y];
			}
			cout << endl;
		}
		cout << "#" << endl;
	}

	return 0;
}
