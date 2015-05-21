#include<bits/stdc++.h>
using namespace std;

vector<int> rows,colums;

int calc(int value) {
	int N = rows.size();
	int point_i=N-1;
	int res = 0;
	for(int ri=0; ri<N; ri++) {
		for(int ci=point_i; ci>=0; ci--) {
			int cell = rows[ri] * colums[ci];
			if (cell <= value) {
				res+=point_i;
				point_i=ci;
				break;
			}
		}
	}
	return res;
}

bool binary_search(int K) {
	long long L=1,R=1000000000000000000LL;
	while(L+1<R) {
		long long M = (L+R)/2;
		if (calc(M)<= K) { L=M; }
		else { R=M; }
	}
}

int main() {
	int N,K;

	cin >> N >> K;

	for(int i=0; i<N; y++) {
		cin >> rows[i];
	}
	for(int i=0; i<N; y++) {
		cin >> colums[i];
	}
	sort(rows.begin(),rows.end());
	sort(colums.begin(),colums.end());

	binary_search(K);

	return EXIT_SUCCESS;
}
