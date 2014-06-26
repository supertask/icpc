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
	int N,M,P;
	int X[110];
	int sum;

	while(cin >> N >> M >> P && N && M && P) {
		sum=0;
		REP(i,1,N+1) {
			cin >> X[i];
			sum+=(X[i]*100);
		}
		if (X[M] == 0) {
			cout << "0" << endl;
		}
		else {
			int ans = (sum/X[M])*(100-P)*0.01;
			cout << ans << endl;
		}
	}

	return 0;
}
