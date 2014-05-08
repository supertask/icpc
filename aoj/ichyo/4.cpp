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

bool isStones[20+1][20+1];
int c=0;
int c_x=10, c_y=10;


void counting(int x, int y) {
	if (isStones[x][y]) {
		c++;
	}
}

void print_search(char d, int l) {
	REP(i,1,l+1) {
		if (d == 'N') {
			c_y++;
			counting(c_x, c_y);
		}
		else if (d == 'E') {
			c_x++;
			counting(c_x, c_y);
		}
		else if (d == 'S') {
			c_y--;
			counting(c_x, c_y);
		}
		else if (d == 'W') {
			c_x--;
			counting(c_x, c_y);
		}
	}
}

int main() {
	int N,M;
	while (true) {
		cin >> N;
		if (N == 0) { break; }
		rep(i,21) {
			rep(j,21) {
				isStones[i][j] = false;
			}
		}
		rep(i,N) {
			int x,y;
			cin >> x >> y;
			isStones[x][y] = true;
		}

		char d;
		int l;
		c=0;
		c_x=10, c_y=10;
		cin >> M;
		rep(i,M) {
			cin >> d >> l;
			print_search(d,l);
		}
		if (c >= N) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}
