/* ナップサック問題をメモ化再帰で解く */
#include<bits/stdc++.h>
#define dump(a) cout << #a << " " << a << endl
#define N_MAX 100
#define W_MAX 10000
using namespace std;

int N,W;
vector<int> weights;
vector<int> values;
int dp[N_MAX+1][W_MAX+1];

int dfs(int i, int w)
{
	if (dp[i][w] != -1) { return dp[i][w]; }

	int res=0;
	if (i == N) { res = 0; }
	else if (w < weights[i]) {
		//重さwに納められないとき
		res = dfs(i+1, w); //何もナップサックに入れない
	}
	else {
		//何もナップサックにいれないときと入れたときのvalueの値を比較して高い値をreturn
		res = max(dfs(i+1,w), dfs(i+1,w-weights[i])+values[i] );
	}
	dp[i][w]=res;
	return res;
}

int main() {
	memset(dp,-1,sizeof(dp));

	cin >> N >> W;
	int v,w;
	for(int i=0; i<N; i++) {
		cin >> v >> w;
		values.push_back(v);
		weights.push_back(w);
	}
	cout << dfs(0,W) << endl; //0番目から計算,W以下

	return EXIT_SUCCESS;
}
