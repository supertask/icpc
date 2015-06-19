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
#define PRIME_MAX 1000000

using namespace std;

int main() {
	bool is_prime[PRIME_MAX];
	
	is_prime[0] = false;
	is_prime[1] = false;
	REP(i,2,PRIME_MAX+1) { is_prime[i] = true; }
	REP(i,2,PRIME_MAX+1) {
		if (is_prime[i]) {
			for(int j=i+i; j<PRIME_MAX+1; j+=i) { is_prime[j] = false; }
		}
	}

	int a,d,N;
	while(cin >> a >> d >> N) {
		if (a==0&&d==0&&N==0) { break; }
		int prime_cnt=0;
		while (true) {
			if (is_prime[a]) { prime_cnt++; }
			if (prime_cnt >= N) { break; }
			a+=d;
		}
		cout << a << endl;
	}

	/*
	int cnt=0;
	for(int i=0; i < PRIME_MAX+1; i++) {
		if (cnt==N) { cout << i << endl; break; }
		if (is_prime[i] && ((i-a)%d==0)) { cnt++; }
	}
	*/

	return 0;
}
