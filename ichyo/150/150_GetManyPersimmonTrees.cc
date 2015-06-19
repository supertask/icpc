/* http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1125 */
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
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl

template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //t=min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //t=max

using namespace std;

int N;
int W,H;
int S,T;

// 1オリジン
struct Point {
	int w;
	int h;
};

vector<Point> ps;

int main() {
	while(cin >> N && N) {
		cin >> W >> H;

		ps.clear();
		int w=0,h=0;
		rep(i,N) {
			cin >> w >> h;
			Point p;
			p.w = w; p.h = h;
			ps.push_back(p);
		}
		cin >> S >> T;

		int cnt=0;
		int rect_h=0,rect_w=0;
		int max_cnt=0;
		REP(h,1,H+1) {
			REP(w,1,W+1) {
				cnt=0;
				rect_w = w + S - 1;
				rect_h = h + T - 1;
				rep(i,ps.size()) { //tree search
					if (w <= ps[i].w && ps[i].w <= rect_w
						&& h <= ps[i].h && ps[i].h <= rect_h) {
						cnt++;		
					}
				}
				chmax(max_cnt,cnt);
			}
		}
		cout << max_cnt << endl;
	}

	return 0;
}
