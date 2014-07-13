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
	
	is_prime[0] = true;
	is_prime[1] = true;
	REP(i,2,PRIME_MAX) { is_prime[i] = true; }
	REP(i,2,PRIME_MAX) {
		if (is_prime) {
			for(int j=i+i; j<PRIME_MAX; j+=i) { is_prime[i] = false; }
		}
	}

	int ans;
	int prime_cnt;
	int a,d,N;
	while(cin >> a >> d >> N) {
		ans=0;
		if (a==0&&d==0&&N==0) { break; }
		ans = a;
		prime_cnt=1;
		dump(N);
		while (true) {
			dump(ans);
			dump(prime_cnt);
			if (prime_cnt >= N) { break; }
			if(is_prime[ans]) { prime_cnt++; }
			ans+=d;
		}
		cout << ans << endl;
	}

	return 0;
}
