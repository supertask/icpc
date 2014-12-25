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

int mapp[49][49];
bool is_visit[49][49];
bool is_goal=false;
int R,C;
int rstart,cstart;
int rgoal,cgoal;
int N;
int r,c,h,w;

int dw[4] = {1,0,-1,0};
int dh[4] = {0,-1,0,1};

void search(int w, int h) {
	if (w == cgoal && h == rgoal) {
		is_goal = true;
		return;
	}

	int aw=0,ah=0;
	rep(i,4) {
		aw = w + dw[i];
		ah = h + dh[i];
		if ((1<=aw && aw<=C) && (1<=ah && ah<=R)) {
			//次の島を訊ねる条件
			if ((mapp[aw][ah] == 1) && (!is_visit[aw][ah])) { 
				is_visit[aw][ah] = true;
				search(aw,ah);
			}
		}
	}
}

int main()
{
	rep(r,49) {
		rep(c,49) {
			mapp[c][r] = 0;
			is_visit[c][r] = false;
		}
	}

	cin >> R >> C;
	cin >> rstart >> cstart;
	cin >> rgoal >> cgoal;
	cin >> N;

	rep(i,N) {
		cin >> r >> c >> h >> w;
		REP(i,r,r+h) {
			REP(j,c,c+w) {
				mapp[j][i] = 1;
				is_visit[j][i] = false;
			}
		}
	}

	if (mapp[cstart][rstart] == 0 || mapp[cgoal][rgoal] == 0)
	{
		cout << "NO" << endl;
	}
	else {
		search(cstart,rstart);
		if (is_goal) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	/*
	REP(r,1,R+1) {
		REP(c,1,C+1) {
			cout << is_visit[c][r] << " ";
		}
		cout << endl;
	}
	cout << endl;

	REP(r,1,R+1) {
		REP(c,1,C+1) {
			cout << mapp[c][r] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}
