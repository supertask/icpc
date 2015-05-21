#include<bits/stdc++.h>
using namespace std;

int main() {
	int N,A;
	bool flower[1000001];

	cin >> N;
	int ans=0;
	for(int i=0; i<N; i++) {
		cin >> A;
		if (flower[A]) {
			ans++;
		}
		flower[A]=true;
	}
	cout << ans << endl;
	
	return EXIT_SUCCESS;
}
