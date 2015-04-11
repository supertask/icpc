/* http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1194&lang=jp */
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
#include<cassert>
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
	int R,N;
	int xl,xr,h;
	int offset = 20;
	cout << fixed << setprecision(4); //固定でかつ浮動小数点誤差範囲

	while(cin >> R >> N)
	{
		if (R == 0 && N == 0) { break; }
		vector<int> max_hs(50,0); //-20<=i<=20

		rep(i,N) {
			cin >> xl >> xr >> h;
			xl = xl + offset;
			xr = xr + offset;
			for(int x = xl; x < xr; x++) { //-2<=x<=-1(点) -> -2<=x<-1(線分)
				max_hs[x] = max(max_hs[x],h);
			}
		}

		/*
		 * ここでのx0,y0とは円の中心座標
		 * y0_left, y0_rightはビルの頂点の左右の点のこと
		 */
		double mini = INT_MAX;
		double y0=0;
		int y=0;
		for(int x = -R; x < R; x++) {
			int xx = x+offset; //配列用のx座標
			y = max_hs[xx];

			int tmp_x = 0;
			if (x < 0) { tmp_x = x+1; } //-2点| -2線 | -1点 | -1線 | 0点 | 0線 | ...
			else { tmp_x = x; }

			//R分のオフセットあり
			y0 = y - sqrt(R*R - tmp_x*tmp_x); //建物の左側または右側の特徴点(x0=0)
			y0 = y0 + R; //中心から距離R上の円上の座標
			chmin(mini,y0);
		}
		cout << mini << endl;
	}

	return 0;
}
