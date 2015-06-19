#include<bits/stdc++.h>
#define PRIME_MAX 500000
using namespace std;

bool prime[PRIME_MAX+1];

int main()
{
	prime[0] = false;
	prime[1] = false;
	for(int i=2; i<PRIME_MAX+1; i++) prime[i] = true; 
	for(int i=2; i<PRIME_MAX+1; i++) {
		if (prime[i]) { for (int j=i+i; j<PRIME_MAX+1; j+=i) prime[j] = false; }
	}

	int N;
	while(cin >> N, N) {
		int cnt=0;
		for(int i=N+1; i<=2*N; i++) {
			if (prime[i]) { cnt++; }
		}
		cout << cnt << endl;
	}
}
