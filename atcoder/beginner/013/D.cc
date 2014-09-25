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

int main()
{
	int N,M,D;
	int index;
	vector<int> A;
	vector<int> to;

	cin >> N >> M >> D;
	int doubling[N+1][31];

	rep(i,M) {
		cin >> index;
		A.push_back(index);
	}
	reverse(ALL(A)); // Why?

	rep(i,N+1) { //0 ~ N
		to.push_back(i);
	}
	
	//阿弥陀のシュミレーション
	rep(i,M) {
		swap(to[A[i]],to[A[i]+1]);
	}

	//ダブリング:工程1
	//NlogDのダブリングテーブル作成
	REP(i,1,N+1) { //一回目
		doubling[i][0] = to[i]; //2^0
	}
	REP(k,1,30) { //2^1 ~ 2^30
		REP(i,1,N+1) {
			int next = doubling[i][k-1]; //2^(k-1)の内のleft
			doubling[i][k] = doubling[next][k-1]; //2^(k-1)の内のright
		}
	}

	//ダブリング:工程2
	REP(i,1,N+1) {
		int next = i;
		int DD = D;

		rep(k,30+1)
		{
			if (DD & 1) {
				next = doubling[next][k];
			}
			DD = DD >> 1;
		}
		cout << next << endl;
	}

	return 0;
}
