/*
 * ICPCのジャッジプログラム
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2400
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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


struct Team {
	int tID;
	int correct_cnt;
	int pena_time;
	bool operator<(const Team& right) const {
		if (correct_cnt == right.correct_cnt) {
			if (pena_time == right.pena_time) {
				return tID < right.tID; //小さい方が左側（順位が上）
			}
			else {
				return pena_time < right.pena_time; //少ない方が左側（順位が上）
			}
		}
		else {
			return correct_cnt > right.correct_cnt; //多い方が左側（順位が上）
		}
	}
};

int main() {
	int T,P,R;
	int tID,pID,time;
	string message;
	int wrong_cnt[51][11]; //T,P
	bool is_correct[51][11];

	while(cin >> T >> P >> R) {
		if (T==0&&P==0&&R==0) break;
		tID = pID = time = 0;
		message = "";
		Team teams[51];

		rep(i,51) {
			teams[i].tID = i;
			teams[i].correct_cnt= 0;
			teams[i].pena_time = 0;
		}
		fill_n((int *)wrong_cnt,sizeof(wrong_cnt)/sizeof(int),0);
		fill_n((int *)is_correct,sizeof(is_correct)/sizeof(int),0);

		rep(r,R) {
			cin >> tID >> pID >> time >> message;
			if (message == "CORRECT") {
				if (!is_correct[tID][pID]) {		
					teams[tID].correct_cnt++;
					teams[tID].pena_time+= wrong_cnt[tID][pID]*1200+time;
					is_correct[tID][pID] = true;
				}
			}
			else {
				wrong_cnt[tID][pID]++;
			}
		}
		sort(teams+1,teams+T+1);
		REP(i,1,T+1) {
			cout << teams[i].tID << " " << teams[i].correct_cnt << " " << teams[i].pena_time << endl;
		}

	}

	return 0;
}
