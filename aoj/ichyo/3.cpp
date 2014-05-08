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

int stones[51];

int main() {
	int N,P;
	while(true) {
		cin >> N >> P;

		int wan = P;
		if (N == 0 && P == 0) { break; }
		rep(i,N) {
			stones[i] = 0;
		}

		int i = 0;
		while(true) {
			if (i >= N) { i = 0; }
			if (wan > 0) {
				wan--;
				stones[i]++;
			}
			else { //空なら
				wan = stones[i];
				stones[i] = 0;
			}
			//cout << i << ": " << stones[i] << " | ";
			if (stones[i] >= P) { 
				//cout << endl;
				cout << i << endl;
				break; 
			} 
			i++;
		}

	}

	return 0;
}
