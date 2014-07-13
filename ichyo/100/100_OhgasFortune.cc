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
#define all(c) (c).begin(), (c).end()

using namespace std;
template<class T> inline void chmax(T& a, T b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, T b) { if(b < a) a = b; }

int main() {
	int T;
	int money,year,N;
	bool is_fukuri;
	double per_year;
	int risoku;
	int risi;

	vector<int> final_moneys;
	cout << setprecision(12) << fixed;
	cin >> T;
	rep(t,T) {
		cin >> money >> year >> N;
		rep(i,N) {
			int moneyT = money;
			cin >> is_fukuri >> per_year >> risoku;

			if (is_fukuri) {
				rep(y,year) {
					moneyT = moneyT*(1+per_year) - risoku;
				}
			}
			else {
				risi=0;
				rep(y,year) {
					risi += moneyT*per_year;
					moneyT-=risoku;
				}
				moneyT = moneyT + risi;
			}
			final_moneys.push_back(moneyT);
		}
		cout << *max_element(all(final_moneys)) << endl;
		final_moneys.clear();
	}


	return 0;
}
