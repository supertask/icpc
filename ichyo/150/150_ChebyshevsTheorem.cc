/* 
 * エラトステネスの篩を使った問題
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1172&lang=jp
 */
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
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define PRIME_MAX 123456*2

using namespace std;

int main() {
	int N;
	bool prime[PRIME_MAX+1];

	prime[0] = false;
	prime[1] = false;
	REP(i,2,PRIME_MAX+1) prime[i] = true;

	//エラトステネスの篩
	REP(i,2,PRIME_MAX+1) {
		if (prime[i]) {  
			for (int j=i+i; j<PRIME_MAX+1; j+=i) prime[j] = false; 
		}
	}

	int prime_cnt;
	while(cin >> N && N) {
		prime_cnt=0;
		REP(i,N+1,2*N+1) { //n < i <= 2*n
			if (prime[i]) {
				prime_cnt++;
			}
		}
		cout << prime_cnt << endl;
	}

	return 0;
}
