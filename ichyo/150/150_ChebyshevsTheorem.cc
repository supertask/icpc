/* 
 * エラトステネスの篩を使った問題
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1172&lang=jp
 */
#include<bits/stdc++.h>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
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

	while(cin >> N && N) {
		cout << count(prime+N+1, prime+2*N+1, true) << endl; //N < x <=2*N
	}

	return EXIT_SUCCESS;
}
