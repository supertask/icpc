#include<bits/stdc++.h>
using namespace std;

int main() {
	int N,S,T,W,A;

	cin >> N >> S >> T;
	cin >> W;
	int ans=0;
	int now_w=0;
	now_w=W;
	if (S <= now_w && now_w <= T) { ans++; }
	for(int i=0; i<N-1; i++) {
		cin >> A;
		now_w+=A;
		if (S <= now_w && now_w <= T) {
			ans++;
		}
	}
	cout << ans << endl;
	
	return EXIT_SUCCESS;
}
