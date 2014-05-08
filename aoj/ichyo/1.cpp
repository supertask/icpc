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
int S[1001] = {0};

int main() {
	int N;

	while(true) {
		cin >> N;

		if (N == 0) { break; }
		rep(i,N) {
			cin >> S[i];
		}
		sort(S,S+N);
		int ave = accumulate(S+1,S+N-1,0) / (N-2);
		cout << ave << endl;
	}
	

	return 0;
}
