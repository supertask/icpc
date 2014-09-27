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

int N,D,X,Y;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int dfs(int x, int y, int cnt, bool[][] is_visit) //nowX, nowY
{
	if (cnt == N) { if (x == X && y == Y) return 1; }
	if (is_visit) { return 0; }
	dump(x+X);
	dump(y+Y);
	is_visit[x+X][y+Y] = true;

	int sum=0;
	rep(i,4) {
		int ax = x+dx[i];
		int ay = y+dy[i];
		if ((-X <= ax && ax <= X) && (-Y <= ay && ay <= Y))
		{
			sum+=dfs(ax,ay,cnt+1, is_visit);
		}
	}
	return sum;
}

int main() {
	
	bool is_minus_x = false;
	bool is_minus_y = false;

	cin >> N >> D >> X >> Y;
	if (X % D == 0 && Y % D == 0)
	{
		X /= D; //要領削減
		Y /= D;
		dump(X);
		dump(Y);
		bool is_visit[2*X][2*Y];
		int cnt = dfs(0,0,0,is_visit); //X,Y,cnt
		cout << cnt << endl;
	}
	else {
		cout << "0.0" << endl;
	}

	return 0;
}
