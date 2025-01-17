/* C 三角錐: まだ */
#include<bits/stdc++.h>
#define dump(a) cout << (#a) << (a) << endl
using namespace std;

#define MAX_SIZE 2000002

//pollok
int memo[MAX_SIZE]; //MAX_SIZE未満
int memo_kisu[MAX_SIZE]; //MAX_SIZE未満
vector<int> all_pks;
vector<int> kisu_pks;

//P=pkの和, index=pksの現在の場所
int dfs(const int P, int memo_cnt[MAX_SIZE], vector<int> &pks)
{
	//dump(level);
	if (P == 0) { return 0; }
	if (memo_cnt[P] != -1) { return memo_cnt[P]; } //メモ化判別
	
	int min_depth = INT_MAX;
	//100通り
	for(int i=0; i<pks.size(); i++) { //大きい順
		int next_P = P-pks[i];
		if (next_P >= 0) {
			int depth = dfs(next_P, memo_cnt, pks) + 1; //通り数（戻り値）
			min_depth = min(min_depth,depth); //最小の通り数
		}
		//マイナスの場合は次
	}
	//値をメモ化
	memo_cnt[P] = min_depth;
	
	return min_depth;
}

int main() {
	int n=1;
	while(true) {
		int pk = n * (n+1) * (n+2) / 6;
		if (pk >= MAX_SIZE){ break; }

		all_pks.push_back(pk);
		if (pk % 2 != 0) { kisu_pks.push_back(pk); }
		n++;
	}
	reverse(begin(all_pks),end(all_pks));
	reverse(begin(kisu_pks),end(kisu_pks));

	memset(memo,-1,sizeof(memo));
	memset(memo_kisu,-1,sizeof(memo_kisu));

	int P;
	while(cin >> P) {
		if (P == 0) { break; }

		int index=0; //
		int left=0,right=0;
		left = dfs(P, memo, all_pks);
		right = dfs(P,memo_kisu, kisu_pks);
		cout << left << " " << right << endl;
	}


	return EXIT_SUCCESS;
}


