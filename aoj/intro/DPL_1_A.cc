#include<bits/stdc++.h>
#define dump(a) cout << #a << " " << a << endl
#define MAX_SIZE 50000
using namespace std;

int N,M;
vector<int> coins;
int memo_cnt[MAX_SIZE+1];

int dfs(const int NN) {
	if (NN == 0) { return 0; }
	if (memo_cnt[NN] != -1) { return memo_cnt[NN]; }

	int min_cnt=INT_MAX;
	for(int i=0; i<M; i++) {
		int next_NN = NN-coins[i];
		if (next_NN >= 0) {
			int depth = dfs(next_NN) + 1;
			min_cnt = min(min_cnt, depth);
		}
	}
	memo_cnt[NN] = min_cnt;

	return min_cnt;
}

int main() {
	int value;
	cin >> N >> M;

	memset(memo_cnt,-1,sizeof(memo_cnt));
	for(int i=0; i<M; i++) {
		cin >> value;
		coins.push_back(value);
	}
	sort(coins.begin(),coins.end());
	reverse(coins.begin(), coins.end());
	/*
	for(int i=0; i<M; i++)
		dump(coins[i]);
	*/

	cout << dfs(N) << endl;

	return EXIT_SUCCESS;
}
