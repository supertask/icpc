/*
 * あみだくじ問題
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2001
 */
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

int main() {
	int N,M,A,H,P,Q;
	int amida[101][1001]; //幅，高さ
	int now_amida;

	while(cin >> N >> M >> A) {
		if (N==0&&M==0&&A==0) break;
		fill_n((int *) amida,sizeof(amida)/sizeof(int),0);
		rep(m,M) {
			cin >> H >> P >> Q;
			amida[P][H] = Q;
			amida[Q][H] = P;
		}

		/*
		rep(h,7) {
			rep(w,7) {
				cout << amida[w][h] << " ";
			}
			cout << endl;
		} */

		now_amida = A;
		for(int h = 1000; h >= 1; h--) {
			if (amida[now_amida][h] > 0) { //次の網だがあるとき
				//dump(now_amida);
				now_amida = amida[now_amida][h]; //今の網だを更新する
			}
		}
		cout << now_amida << endl;
	}

	return 0;
}
