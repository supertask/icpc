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
	int cnt;
	int sumi;

	while (cin >> N && N) {
		cnt=0;
		REP(i,1,N+1) {
			sumi=0;
			REP(ii,i,N+1) {
				if (sumi>=N) {
					if (sumi == N) { 
						cnt++; 
					}
					break;
				}
				sumi+=ii;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
