#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#include<sstream>
#include<cassert>
#define PRIME_MAX 100001
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //t=min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //t=max
using namespace std;

vector<int> primes;
vector<int> primes_super;

int M(int N, int P)
{
	int b;
	rep(i,primes.size()) {
		if(primes[i] > P){ b = i; break; }
	}

	REP(i,0,100) {
		REP(j,i,100) {
			primes_super.push_back(primes[i] + primes[j]);
		}
	}
	return primes_super[N-1];
}


int main()
{
	bool is_prime[PRIME_MAX];

	int N,P;
	is_prime[0] = false;
	is_prime[1] = false;
	REP(i,2,PRIME_MAX) is_prime[i] = true;
	REP(i,2,PRIME_MAX) {
		if (is_prime[i]) {
			for (int j=i+i; j<PRIME_MAX; j+=i) is_prime[j] = false;
		}
	}
	rep(i,PRIME_MAX) { if (is_prime[i]) primes.push_back(i); }

	while(cin >> N >> P)
	{
		if (N==-1&&P==-1) { break; }
		cout << M(N,P) << endl;
	}

	return 0;
}
