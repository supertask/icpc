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

long long score=0;
int area_A[51][51];
bool area_B[51][51],area_C[51][51];
int H,W,h,w;

bool is_template_match(int x, int y) {
	score=0;
	rep(ty,h) {
		rep(tx,w) {
			if (y+ty > H || x+tx > W) {
				return false;
			}
			if (area_B[y+ty][x+tx] != area_C[ty][tx]) {
				return false;
			}
			score += area_A[y+ty][x+tx];
		}
	}
	return true;
}

//テンプレートマッチング
int main() {
	cin >> H >> W;
	rep(y,H) rep(x,W) cin >> area_A[y][x];
	rep(y,H) rep(x,W) cin >> area_B[y][x];
	cin >> h >> w;
	rep(y,h) rep(x,w) cin >> area_C[y][x];

	bool is_NA=true; //一度もマッチしていない
	long long max_score=LONG_MIN;
	rep(y,H) {
		rep(x,W) {
			if (is_template_match(x,y)) {
				max_score = max(max_score,score);
				is_NA=false;
			}
		}
	}
	if (is_NA) { cout << "NA" << endl; }
	else { cout << max_score << endl; }

	return EXIT_SUCCESS;
}
