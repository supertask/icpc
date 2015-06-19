/* ナップサック問題をメモ化再帰で解く */
#include<bits/stdc++.h>
#define dump(a) cout << #a << " " << a << endl
#define MAX_SIZE 25
using namespace std;

int N,W;
vector<pair<int,int>> inputs;
int dp[MAX_SIZE+1][MAX_SIZE+1];

/*
 * w = 重さ, dollar = 必要なお金
 */
int dfs(int w, int dollar)
{
	if () {}
}

int main() {
	memset(dp,-1,sizeof(dp));

	cin >> N >> W;
	for(int i=0; i<N; i++) {
		cin >> v >> w;
		inputs.push_back(make_pair(v,w));
	}
	int dollar = 0;
	dfs(W,dollar);

	return EXIT_SUCCESS;
}
