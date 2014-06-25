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

int N,D;
bool is_yes;
int XX,YY;

void saiki(int X, int Y) {
	if (X == 0 && Y == 0) {
		is_yes = true;
		return;
	}
	else if (X < 0 || Y < 0 || XX < X || YY < Y) {
		return;
	}
	else {
		cout << X << " " << Y << endl;
		cout << is_yes << endl;
		saiki(X+D,Y);
		saiki(X,Y+D);
		saiki(X-D,Y);
		saiki(X,Y-D);
	}
}

int main() {
	int X,Y;
	is_yes = false;
	cin >> N >> D;
	cin >> X >> Y;
	XX = X;
	YY = Y;
	if (X % D == 0 && Y % D == 0) {
		saiki(X,Y);
		cout << is_yes << endl;
	}
	else {
		cout << "0.0" << endl;
	}

	return 0;
}
