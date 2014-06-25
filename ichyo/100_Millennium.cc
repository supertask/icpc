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


int main() {
	int N;
	int year,month,day;
	int day_limit;
	int cnt;

	cin >> N;
	rep(i,N) {
		cnt=0;
		cin >> year >> month >> day;
		while(true) {
			if (year % 3 == 0) { //すべて大の月
				day_limit = 20;
			}
			else {  
				if (month % 2 == 0) { //小の月
					day_limit = 19;
				}
				else { //大の月
					day_limit = 20;
				}
			}
			if (day >= day_limit) {
				day = 1;
				if (month >= 10) {
					month = 1;
					if (year >= 999) { break; }
					else { year++; }
				}
				else { month++; }
			}
			else { day++; }
			cnt++;
		}
		cout << cnt+1 << endl;
	}

	return 0;
}
