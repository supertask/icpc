#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<climits>
#include<ctime>
#include<cstring>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_    str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()
using namespace std;

typedef struct team {
	team() {
		index = 0;
		prob = 0;
		min = 0;
		back_min = 0;
	}
	int index;
	int prob;
	int min;
	int back_min;
	bool operator<(const team& right) const {
		if (prob == right.prob) {
			if (min == right.min) {
				return index > right.index;
			}
			else {
				return min < right.min;
			}
		}
		else {
			return prob > right.prob;
		}
	}
} Team;

int main() {
	int M,T,P,R;
	int m,t,p,j;

	while(true) {
		cin >> M >> T >> P >> R;
		if (M == 0 && T == 0 && P == 0 && R == 0) { break; }
		//cout << M << " "<< T << " "<< P << " "<< R << " " << endl;
		vector<Team> teams(T+1);
		REP(i,1,T+1) {
			teams[i].index = i;
		}
		rep(i,R) { //O(R:2000)
			cin >> m >> t >> p >> j;
			if (j == 0) { //AC
				teams[t].index = t;
				teams[t].min += m; // - teams[t].back_min;
				//teams[t].back_min = m;
				teams[t].prob++;
			}
			else { //ERR
				teams[t].min += 20;
			}
		}
		sort(all(teams));
		int back_min = 0;
		int back_prob = 0;
		rep(i,teams.size()) {
			if (teams[i].index == 0) { continue; }
			if (teams[i].min == back_min && teams[i].prob == back_prob) { 
				eqls.push_back(teams[i].index);
			}
			else {
			}
			/*
			cout << "team: " << teams[i].index;
			cout << " problem: " << teams[i].prob;
			cout << " min: " << teams[i].min;
			cout << endl;
			*/
			back_min = teams[i].min;
			back_prob = teams[i].prob;
		}
		cout << endl;
	}

	return 0;
}
