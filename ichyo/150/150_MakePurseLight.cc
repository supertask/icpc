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

int moneys[4] = {10,50,100,500};

int main() {
	int money;
	int money_nums[4];	
	
	while(cin >> money, money) {
		fill_n((int *)money_nums,sizeof(money_nums)/sizeof(int),0);
		rep(i,4) {
			cin >> money_nums[i];
		}
		rep(i,4) {
			if (money_nums[i] > 0) {
				int money_num = money_nums[i];
				REP(m,1,money_num+1) {
					
				}
			}
			//0のときパス
		}
	}

	return 0;
}
